#include <iostream>
#include <string>

class transport{
protected:

	std::string type;
	std::string brand;
	float volume_of_engine;
	int max_speed;
	int cost;
	bool radio;
	std::string name_of_song;
	int transmission;
	std::string gearbox;
	bool work;
public:
	//геттеры

	std::string getType()
	{
		return type;
	}

	std::string getBrand()
	{
		return brand;
	}

	float getVolume_of_engine()
	{
		return volume_of_engine;
	}

	int getMax_speed() 
	{
		return max_speed;
	}

	int getCost()
	{
		return cost;
	}

	int getTransmission()
	{
		return transmission;
	}

	std::string getGearbox()
	{
		return gearbox;
	}

	//сеттеры
	void setType(std::string type)
	{
		this -> type = type;
	}
	
	void setBrand(std::string brand)
	{
		this->brand = brand;
	}

	void setVolume_of_engine(float volume_of_engine)
	{
		this->volume_of_engine = volume_of_engine;
	}

	void setMax_speed(int max_speed)
	{
		this->max_speed = max_speed;
	}
	
	void setCost(int cost)
	{
		this->cost = cost;
	}

	void setGearbox(std::string gearbox)
{
    if (gearbox == "mechanics")
    {
        this->gearbox = "mechanics";
    }
    else if (gearbox == "automatic")
    {
        this->gearbox = "automatic";
    }
    else
    {
        this->gearbox = "unknown";
    }
}

	void printInfo() const
	{
		std::cout << "Type: " << type << "\n";
		std::cout << "Brand: " << brand << "\n";

		if (volume_of_engine == -1)
			std::cout << "Engine volume: unknown\n";
		else if (volume_of_engine == 0)
			std::cout << "Engine volume: this transport does not have this feature.\n";
		else
			std::cout << "Engine volume: " << volume_of_engine << "\n";

		if (max_speed == -1)
			std::cout << "Max speed: unknown\n";
		else
			std::cout << "Max speed: " << max_speed << " km/h" << "\n";

		if (cost == -1)
			std::cout << "Cost: unknown\n";
		else
			std::cout << "Cost: " << cost << " $" << "\n";

		if (gearbox == "unknown")
			std::cout << "Gearbox: unknown\n";
		else
			std::cout << "Gearbox: " << gearbox << "\n";

		if (!work)
			std::cout << "Engine: off\n";
		else
			std::cout << "Engine: running\n";

		if (!radio)
			std::cout << "Radio: off \n";
		else
			std::cout << "Radio: playing \"" << name_of_song << "\"\n";

		std::cout << "Transmission: ";

		if (transmission == 0)
			std::cout << "N\n";
		else if (transmission == -1)
			std::cout << "not supported\n";
		else
			std::cout << transmission << "\n";

		std::cout << "---------------------------\n";
	}

	virtual void start_the_transport() = 0;//завести машину

	virtual void turn_on_the_radio() = 0;//вкл/выкл радио

	virtual void change_the_song(std::string name_of_song) = 0;//сменить мелодию на свою(если такова имеется)

	virtual void  change_transmission(int transmission) = 0;//изменить передачу(если механика) или изменить режим движения автомобиля


};

class car: public transport
{
	//std::string type;
	//std::string brand;
	//float volume_of_engine;
	//int max_speed;
	//int cost;
	//bool radio;
	//std::string name_of_song;
	//int transmission;
public:
	car(std::string brand)
	{
		this->brand = brand;
		this->type = "car";
		this->volume_of_engine = -1;
		this->max_speed = -1;
		this->cost = -1;
		this->radio = false;
		this->name_of_song = "...";
		this->transmission = 0;
		this->gearbox = "mechanics";
		this->work = false;
	}


	void start_the_transport()
	{
		this->work = true;
	}

	void change_transmission(int transmission)
	{	
		if (this->work == true)
		{
			this->transmission = transmission;
		}
		else
		{
			std::cout << type << " doesn't work\n";
		}
	}

	void change_the_song(std::string name_of_song)
	{
		if (this->radio == true)
		{
			this->name_of_song = name_of_song;
		}
		else
		{
			std::cout << "radio doesn't work\n";
		}
	}

	void turn_on_the_radio()
	{
		this->radio = !this->radio;
	}

};

class plane : public transport {
public:
	plane(std::string brand) {
		this->brand = brand;
		this->type = "plane";
		this->volume_of_engine = -1;
		this->max_speed = -1;
		this->cost = -1;
		this->radio = false;
		this->name_of_song = "...";
		this->transmission = -1;
		this->gearbox = "mechanics";
		this->work = false;
	}

	void start_the_transport()
	{
		this->work = true;

	}

	void change_transmission(int) override
	{

		std::cout << "plane: transmission is not supported\n";
	}

	void change_the_song(std::string name_of_song)
	{
		if (this->radio == true)
		{
			this->name_of_song = name_of_song;
		}
		else
		{
			std::cout << "radio doesn't work\n";
		}
	}

	void turn_on_the_radio()
	{
		radio = false;  // всегда false
		std::cout << "Plane has no radio\n";
	}
};

class electric_car : public transport
{
public:
	electric_car(std::string brand)
	{
		this->brand = brand;
		this->type = "electric_car";
		this->volume_of_engine = 0;  
		this->max_speed = -1;
		this->cost = -1;
		this->radio = false;
		this->name_of_song = "...";
		this->transmission = 0;        
		this->gearbox = "automatic";   
		this->work = false;
	}

	void start_the_transport()
	{
		this->work = true;
	}

	void change_transmission(int transmission)
	{
		if (this->work == true)
		{
			// допустим: 0=N, 1=D, 2=R
			if (transmission == 0 || transmission == 1 || transmission == 2)
			{
				this->transmission = transmission;
			}
			else
			{
				std::cout << "electric_car: transmission can be only 0(N), 1(D), 2(R)\n";
			}
		}
		else
		{
			std::cout << type << " doesn't work\n";
		}
	}

	void change_the_song(std::string name_of_song)
	{
		if (this->radio == true)
		{
			this->name_of_song = name_of_song;
		}
		else
		{
			std::cout << "radio doesn't work\n";
		}
	}

	void turn_on_the_radio()
	{
		this->radio = !this->radio;
	}
};



int main()
{
	car c("BMW");
	c.turn_on_the_radio();
	c.change_the_song("Organ Penguin Version");
	c.setCost(40000);
	c.setMax_speed(280);
	c.start_the_transport();
	c.change_transmission(1);
	c.printInfo();

	plane p("Boeing");
	p.setCost(100000000);
	p.setMax_speed(900);
	p.start_the_transport();
	p.turn_on_the_radio();
	p.change_the_song("antidepressant");
	p.change_transmission(3); 
	p.printInfo();

	electric_car e("Tesla");
	e.turn_on_the_radio();
	e.change_the_song("Kopendos");
	e.setCost(60000);
	e.setMax_speed(250);
	e.start_the_transport();
	e.change_transmission(1);
	e.printInfo();
}