#pragma once
#include <Equilateral_shapes.hpp>


	class Scene
	{
	public:
		Scene(int width, int height);
		~Scene();
		void LifeCycle();

	private:
		std::unique_ptr<Camera> m_camera;

		int m_width;
		int m_height;

		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;

		std::unique_ptr<Cube> cube1;

	};
