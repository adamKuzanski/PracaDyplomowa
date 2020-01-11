#ifndef SECRETMODEVIEW_HPP
#define SECRETMODEVIEW_HPP

#include <gui_generated/secretmode_screen/SecretModeViewBase.hpp>
#include <gui/secretmode_screen/SecretModePresenter.hpp>

class SecretModeView : public SecretModeViewBase
{
public:
    SecretModeView();
    virtual ~SecretModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SECRETMODEVIEW_HPP
