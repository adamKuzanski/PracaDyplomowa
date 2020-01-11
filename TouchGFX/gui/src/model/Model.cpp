#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0), speedValue(0), counter(0)
{
}

void Model::tick()
{
	counter++;
	if(counter%3 == 1)
	{
		static int add = 1;
		if(speedValue == 120)
		{
			add = -1;
		}
		else if (speedValue == 0)
		{
			add = 1;
		}
	
		speedValue += add;
		modelListener->speed_value_updated(speedValue);
	}
}

void Model::speedValueChangeRequested(int value)
{
	speedValue = value;
}
