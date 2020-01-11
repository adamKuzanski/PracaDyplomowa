#ifndef SECRETMODEPRESENTER_HPP
#define SECRETMODEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SecretModeView;

class SecretModePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SecretModePresenter(SecretModeView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SecretModePresenter() {};

private:
    SecretModePresenter();

    SecretModeView& view;
};


#endif // SECRETMODEPRESENTER_HPP
