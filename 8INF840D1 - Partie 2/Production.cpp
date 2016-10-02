#include "Production.h"

std::condition_variable cv;
std::mutex m;

Production::Production()
{
	m_MT = new File<Piece>();
	m_MJ = new File<Piece>();
	m_MA = new File<Piece>();
	m_MP = new File<Piece>();
	m_Piston = new File<Piece>();

	m_box = new File<Piece>();
	while(m_numberHead <100 || m_numberAxis <100 || m_numberSkirt <100){
		int pieceType = (rand() % 3);
		Piece* p = new Piece(pieceType);
		m_box->enfiler(*p);
		switch (pieceType)
		{
		case 0:
			++m_numberHead;
			break;
		case 1:
			++m_numberSkirt;
			break;
		case 2:
			++m_numberAxis;
		}
	}
	cout << "Total des pieces dans le carton" << endl;

	cout << "Pieces tête : " << m_numberHead << endl;
	cout << "Pieces jupes : " << m_numberSkirt << endl;
	cout << "Pieces axes : " << m_numberAxis << endl;

}

Production::~Production()
{
}

void Production::initStack()
{
	while (!(m_box->estVide())) {
		Piece p = m_box->premier();
		m_box->defiler();
		switch (p.getType())
		{
		case Type::HEAD :
			m_MT->enfiler(p);
			break;
		case Type::SKIRT :
			m_MJ->enfiler(p);
			break;
		case Type::AXIS :
			m_MA->enfiler(p);
			break;
		}
		
	}
	
}

void Production::usinage(File<Piece>* file)
{
	int manufacturingTime = 0;
	switch (file->premier().getType())
	{
	case Type::HEAD:
		manufacturingTime = 120; //represents 2 min in real time
		break;
	case Type::SKIRT:
		manufacturingTime = 180;
		break;
	case Type::AXIS:
		manufacturingTime = 150;
		break;
	}
	while (m_Piston->taille() <  100 && !file->estVide()) {
		Piece p = file->premier();
		std::this_thread::sleep_for(std::chrono::milliseconds(manufacturingTime)); // represents the time of manufacturing

		while (pieceAlreadyOnProduction(p.getType())) {
			//Wait the end of previous fabrication from the MP machine 
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk);
		}
		file->defiler();

		m.lock();
		m_MP->enfiler(p);
		m.unlock();
		
		if (rand() % 4 == 0) {
			std::this_thread::sleep_for(std::chrono::milliseconds(300 + (rand() % 300))); // represents time of fixing, between 5 and 10 minutes in real time
		}
	}
}

void Production::launch()
{
	while (m_Piston->taille() <  100) {
		if (m_MP->taille() == 3) {
			m.lock();
			while (!m_MP->estVide()) {
				m_MP->defiler();
			}
			m.unlock();
			cv.notify_all();
			std::this_thread::sleep_for(std::chrono::milliseconds(60)); // represents the time of manufacturing
			if (rand() % 4 == 0) {
				std::this_thread::sleep_for(std::chrono::milliseconds(300 + (rand() % 300))); // represents time of fixing, between 5 and 10 minutes in real time
			}
			Piece* p = new Piece(3); // Creation of piece Piston
			m_Piston->enfiler(*p);
			cout << "Creation de la piece piston n°" << m_Piston->taille() << endl;
		}
	}
}

bool Production::pieceAlreadyOnProduction(Type type) const
{
	m.lock();
	if (!m_MP->estVide()) {
		if (m_MP->taille() < 3 && (m_MP->premier().getType() == type || m_MP->dernier().getType() == type)) {
			m.unlock();
			return true;
		}
	}
	m.unlock();
	return false;
}


File<Piece>* Production::getBox()
{
	return m_box;
}

File<Piece>* Production::getMT()
{
	return m_MT;
}

File<Piece>* Production::getMJ()
{
	return m_MJ;
}

File<Piece>* Production::getMA()
{
	return m_MA;
}

File<Piece>* Production::getMP()
{
	return m_MP;
}

File<Piece>* Production::getPiston()
{
	return m_Piston;
}




int main()
{



	Production prod = Production();
	thread *t;

	t = new thread[4];




	clock_t begin = clock();

	prod.initStack();

	File<Piece>* MT = prod.getMT();
	File<Piece>* MJ = prod.getMJ();
	File<Piece>* MA = prod.getMA();
	File<Piece>* MPistons = prod.getPiston();


	cout << "Bloc MT : " << *MT << endl;

	cout << "Bloc MJ : " << *MJ << endl;

	cout << "Bloc MA : " << *MA << endl;

	// Constructs the new thread and runs it. Does not block execution.

	t[0] = thread(&Production::usinage, prod, MT);
	t[1] = thread(&Production::usinage, prod, MJ);
	t[2] = thread(&Production::usinage, prod, MA);
	t[3] = thread(&Production::launch, prod);

	// Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.

	cout << "Execution parallele" << endl;
	t[0].join();
	t[1].join();
	t[2].join();
	t[3].join();
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << "Fin de l'execution parallele ; temps d'execution : " << elapsed_secs << " ; Temps reel estime : " << (elapsed_secs * 1000) /60 << " min" << endl;
	cout << "Pistons : " << *MPistons << endl;

	system("pause");
	return EXIT_SUCCESS;
}
