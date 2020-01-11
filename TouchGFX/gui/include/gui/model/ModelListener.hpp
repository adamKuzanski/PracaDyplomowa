#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void speed_value_updated(int speed_value);
protected:
    Model* model;
};

inline void ModelListener::speed_value_updated(int speed_value)
{
}

#endif // MODELLISTENER_HPP
