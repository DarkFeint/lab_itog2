#include <scene.hpp>



	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture);

		Intrinsic intrinsic = { double(m_width/2),(double)(m_height/2), (double)(m_width/2), (double)(m_height/2) };
		Point position = { 0.0, 0.0, 0.0 };
		Angles angles = { 0.0,0.0,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);

		/*m_points = new Point[200000];

		double r = 1;
		for (double fi = 0; fi < 6.28; fi += 0.01)
			for (double teta = 0; teta < 1.57; teta += 0.01)
			{
				m_points[m_size].x = r * sin(teta) * cos(fi);
				m_points[m_size].y = r * sin(teta) * sin(fi) + 5;
				m_points[m_size].z = r * cos(teta);
				m_size++;
			}*/

		Point position_cube = {5.0, 7.0, 0.0};
		double side = 1;

		 cube1 = std::make_unique<Cube>(side, position_cube);

	}
	Scene::~Scene()
	{
		
	}

	void Scene::LifeCycle()
	{
		

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				m_camera->dZ(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_camera->dZ(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_camera->dX(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_camera->dX(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_camera->dPitch(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_camera->dPitch(0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_camera->dRoll(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_camera->dRoll(0.02);
			}

			
			
			
				cube1->Move();
			
			
			/*y0 += 0.02;
			m_size = 0;
			double r = 1;
			for (double fi = 0; fi < 6.28; fi += 0.01)
				for (double teta = 0; teta < 1.57; teta += 0.01)
				{
					m_points[m_size].x = r * sin(teta) * cos(fi);
					m_points[m_size].y = r * sin(teta) * sin(fi);
					m_points[m_size].z = r * cos(teta);
					m_size++;
				}
				*/

			// Проецирование точек
			for (int i = 0; i < cube1->GetSize(); i++)
				m_camera->ProjectPoint(cube1->GetPoints(i), { 255, 0 ,0, 255 });

			m_texture->update((uint8_t*)m_camera->Picture(), m_width, m_height, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}
	}
