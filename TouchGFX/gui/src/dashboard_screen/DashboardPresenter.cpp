#include <gui/dashboard_screen/DashboardView.hpp>
#include <gui/dashboard_screen/DashboardPresenter.hpp>

DashboardPresenter::DashboardPresenter(DashboardView& v)
    : view(v)
{
}

void DashboardPresenter::activate()
{

}

void DashboardPresenter::deactivate()
{

}

void DashboardPresenter::speed_value_change_requested(int value)
{
	view.speed_value_updated(value);
	// model->speedValueChangeRequested(value);
}

void DashboardPresenter::speed_value_updated(int value)
{
	view.speed_value_updated(value);
}
