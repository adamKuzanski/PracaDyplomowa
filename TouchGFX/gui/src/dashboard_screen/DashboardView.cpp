#include <gui/dashboard_screen/DashboardView.hpp>
#include <string>
#include "touchgfx/Color.hpp"

DashboardView::DashboardView()
{

}

void DashboardView::setupScreen()
{
    DashboardViewBase::setupScreen();
	textSpeedDigits.setWildcard(textSpeedDigitsBuffer);
	textBatteryLevel.setWildcard(textBatteryLevelBuffer);
}

void DashboardView::tearDownScreen()
{
    DashboardViewBase::tearDownScreen();
}

void DashboardView::updateSpeedCircle(int value)
{
	presenter->speed_value_change_requested(value);
	circleSpeedInfo.setValue(value);
	circleSpeedInfo.invalidate();
	textSpeedDigits.setTypedText(TypedText(value));
	textSpeedDigits.invalidate();
}


void DashboardView::speed_value_updated(uint16_t value)
{
	circleSpeedInfo.setValue(value);
	circleSpeedInfo.invalidate();
	
	Unicode::snprintf(textSpeedDigitsBuffer, 4, "%d", value);
	textSpeedDigits.invalidate();

	int batteryLevel;
	if (value > 100) batteryLevel = 100;
	else batteryLevel = value;
	lineProgressBatteryLevel.setValue(batteryLevel);
	Unicode::snprintf(textBatteryLevelBuffer, 4, "%d", batteryLevel);
	textBatteryLevel.invalidate();
	// todo, add changing colors

	circleProgressStateOfCharge.setValue(batteryLevel);
	if(batteryLevel >= 40)
	{
		circleProgressStateOfChargePainter.setColor(Color::getColorFrom24BitRGB(0, 255, 4));
		textAreaStateOfCharge.setColor(Color::getColorFrom24BitRGB(0, 255, 4));
	}
	else if(batteryLevel <= 50 && batteryLevel >= 15)
	{
		circleProgressStateOfChargePainter.setColor(Color::getColorFrom24BitRGB(234, 255, 0));
		textAreaStateOfCharge.setColor(Color::getColorFrom24BitRGB(234, 255, 0));
	}
	else
	{
		circleProgressStateOfChargePainter.setColor(Color::getColorFrom24BitRGB(255, 0, 0));
		textAreaStateOfCharge.setColor(Color::getColorFrom24BitRGB(255, 0, 0));
	}
	circleProgressStateOfCharge.invalidate();
	Unicode::snprintf(textAreaStateOfChargeBuffer, 4, "%d", batteryLevel);
	textAreaStateOfCharge.invalidate();

	int powerBalance = (batteryLevel - 50) / 5;
	Unicode::snprintf(textAreaPowerBalanceBuffer1, 3, "%d", abs(powerBalance));
	Unicode::snprintf(textAreaPowerBalanceBuffer2, 2, "%d", abs(powerBalance));
	textAreaPowerBalance.invalidate();

	if(powerBalance < 0)
	{
		textAreaPowerBalance.setColor(Color::getColorFrom24BitRGB(255, 0, 0));
	}
	else
	{
		textAreaPowerBalance.setColor(Color::getColorFrom24BitRGB(0, 255, 4));
	}



	if(powerBalance >= 0)
	{
		circleProgressDischarging.setValue(0);
		circleProgressCharging.setValue(powerBalance);
	}
	else
	{
		circleProgressCharging.setValue(0);
		circleProgressDischarging.setValue(abs(powerBalance));
	}

	circleProgressDischarging.invalidate();
	circleProgressCharging.invalidate();

	
	
	
	
}
