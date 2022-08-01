#pragma once
#include <camera.hpp>

class Object
{
public:

	Object(double side, Point position)
	{
		m_side = side;
		m_position = position;
		m_origin = position;

		m_fig = true;
		m_t = 0;
	}

	virtual ~Object()
	{


	}

	void Move()
	{
		//m_position.y += 0.01;

		for (int i = 0; i < m_size; i++)
		{
			m_points[i].y += 0.01;
		}
		
		/*
		if (m_fig == true)
		{
			//m_position.x = m_position.x + 1 * m_t - 1 * sin(m_t);

			//m_position.z = m_position.z - 1 + 1 * cos(m_t);
			
			
			for (int i = 0; i < m_size; i++)
			{
				if (GetY(i) < 1 + GetOrY())
				{
					m_points[i].y = m_points[i].y + 1 * m_t - 1 * sin(m_t);
					m_points[i].z = m_points[i].z - 1 + 1 * cos(m_t);
					m_points[i].x = m_points[i].x;
				}
				
				
			}


			m_t += 0.01;
		}
	   */

	}

	void SetFigTrue()
	{
		m_fig = true;
	}

	void SetFigFalse()
	{
		m_fig = false;
	}

	int GetSize()
	{
		return m_size;
	}

	Point GetPoints(int i)
	{
		return m_points[i];
	}

	double GetX(int i)
	{
		return m_points[i].x;
	}

	double GetY(int i)
	{
		return m_points[i].y;
	}

	double GetZ(int i)
	{
		return m_points[i].z;
	}

	double GetOrX()
	{
		return m_origin.x;
	}
	double GetOrY()
	{
		return m_origin.y;
	}
	double GetOrZ()
	{
		return m_origin.z;
	}


	/*void Rotate()
	{
		double a = m_angles.roll;
		double b = m_angles.pitch;
		double g = m_angles.yaw;

		double cosa = cos(a);
		double cosb = cos(b);
		double sina = sin(a);
		double sinb = sin(b);

		Mat33d R({ {
						  {cosb, 0, -sinb},
						  {-sina * sinb, cosa, -sina * cosb},
						  {cosa * sinb, sina, cosa * cosb}
				  } });

		Vec3d P({ {
						 {X - m_position.x},
						 {Y - m_position.y},
						 {Z - m_position.z}
				 } });

		Vec3d P_res;

		P_res = R * P;

		double x = P_res.get(0, 0);
		double y = P_res.get(1, 0);
		double z = P_res.get(2, 0);
	}*/



protected:
	double m_side;
	double m_t;
	Point m_position;
	Point m_origin;
	Point* m_points = nullptr;
	int m_size = 0;
	bool m_fig;
	//Angles m_angles;
};

class Cube : public Object
{
public:



	Cube(double side, Point position) : Object(side, position)
	{
		m_points = new Point[1000000 * (int)(side + 1)];

		for (double i = -(side / 2); i < (side / 2); i += 0.05)
		{
			for (double j = -(side / 2); j < (side / 2); j += 0.05)
			{
				for (double k = -(side / 2); k < (side / 2); k += 0.05)
				{
					m_points[m_size].x = i + m_position.x;
					m_points[m_size].y = j + m_position.y;
					m_points[m_size].z = k + m_position.z;
					m_size++;
				}
			}


		}
	}

	int GetMSize()
	{
		return m_size;
	}

	Point GetMPoints(int i)
	{
		return m_points[i];
	}

	virtual ~Cube()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}


};

/*class Sphere : public Object
{
public:

	Sphere(double side, Point position) : Object(side, position)
	{
		m_points = new Point[];

		for (double i = -(side) / 2; i < (double)(side / 2); i += 0.01)
		{
			m_points[m_size].x = i + m_position.x;
			m_points[m_size].y = i + m_position.y;
			m_points[m_size].z = i + m_position.z;
			m_size++;
		}
	}

	virtual ~Sphere()
	{
		delete[] m_points;
	}
private:

};*/
