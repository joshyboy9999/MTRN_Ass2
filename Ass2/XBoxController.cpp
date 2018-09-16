#include "XBoxController.h"

#include "XInputWrapper.h"
#include <math.h>


GamePad::XBoxController::XBoxController(XInputWrapper * xinput, DWORD id)
{
	this->xinput = xinput;
	ctrl_ID = id;
	
}

DWORD GamePad::XBoxController::GetControllerId()
{
	return ctrl_ID;
}

bool GamePad::XBoxController::IsConnected()
{
	if (xinput == NULL) {
		return false;
	}
	if (XInputGetState(ctrl_ID, &ctrl_state) == ERROR_DEVICE_NOT_CONNECTED) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

bool GamePad::XBoxController::PressedA()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_A) == XINPUT_GAMEPAD_A) {
		return true;
	} else {
		return false;
	}
}

bool GamePad::XBoxController::PressedB()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_B) == XINPUT_GAMEPAD_B) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedX()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_X) == XINPUT_GAMEPAD_X) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedY()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_Y) == XINPUT_GAMEPAD_Y) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftShoulder()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) == XINPUT_GAMEPAD_LEFT_SHOULDER) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedRightShoulder()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) == XINPUT_GAMEPAD_RIGHT_SHOULDER) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftDpad()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) == XINPUT_GAMEPAD_DPAD_LEFT) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedRightDpad()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) == XINPUT_GAMEPAD_DPAD_RIGHT) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedUpDpad()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) == XINPUT_GAMEPAD_DPAD_UP) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedDownDpad()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) == XINPUT_GAMEPAD_DPAD_DOWN) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedStart()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_START) == XINPUT_GAMEPAD_START) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedBack()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) == XINPUT_GAMEPAD_BACK) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedLeftThumb()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) == XINPUT_GAMEPAD_DPAD_LEFT) {
		return true;
	}
	else {
		return false;
	}
}

bool GamePad::XBoxController::PressedRightThumb()
{
	if ((ctrl_state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) == XINPUT_GAMEPAD_DPAD_RIGHT) {
		return true;
	}
	else {
		return false;
	}
}

BYTE GamePad::XBoxController::LeftTriggerLocation()
{
	return ctrl_state.Gamepad.bLeftTrigger;
}

BYTE GamePad::XBoxController::RightTriggerLocation()
{
	return ctrl_state.Gamepad.bRightTrigger;
}


GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation()
{
	xinput->XInputGetState(ctrl_ID, &ctrl_state);
	GamePad::Coordinate R_thumb(ctrl_state.Gamepad.sThumbRX, ctrl_state.Gamepad.sThumbRY);
	short L_X = L_thumb.GetX();
	short L_Y = L_thumb.GetY();

	float L_magnitude = sqrt(L_X *L_X + L_Y * L_Y);

	if (L_magnitude > 32767) {
		L_magnitude = 32767;
	}
	if (L_magnitude > deadzone) {
		float normalisedLX = L_X / L_magnitude;
		float normalisedLY = L_Y / L_magnitude;
		L_magnitude = L_magnitude - deadzone;
		// make it into a scale
		float L_scale = L_magnitude * 32767 / (32767 - deadzone);
		// set the new value
		L_thumb.SetX(normalisedLX * L_scale);
		L_thumb.SetY(normalisedLY *L_scale);

	}
	else {
		L_thumb.SetX(0);
		L_thumb.SetY(0);

		return L_thumb;
	}
}

GamePad::Coordinate GamePad::XBoxController::RightThumbLocation()
{
	xinput->XInputGetState(ctrl_ID, &ctrl_state);
	GamePad::Coordinate R_thumb(ctrl_state.Gamepad.sThumbRX, ctrl_state.Gamepad.sThumbRY);
	short R_X = R_thumb.GetX();
	short R_Y = R_thumb.GetY();

	float R_magnitude = sqrt(R_X *R_X + R_Y * R_Y);

	if (R_magnitude > 32767) {
		R_magnitude = 32767;
	}
	if (R_magnitude > deadzone) {
		float normalisedRX = R_X / R_magnitude;
		float normalisedRY = R_Y / R_magnitude;
		R_magnitude = R_magnitude - deadzone;
		// make it into a scale
		float R_scale = R_magnitude * 32767 / (32767 - deadzone);
		// set the new value
		R_thumb.SetX( normalisedRX * R_scale);
		R_thumb.SetY( normalisedRY *R_scale);

	}
	else {
		R_thumb.SetX(0);
		R_thumb.SetY(0);
	}
	return R_thumb;
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right)
{
	ctrl_vib.wLeftMotorSpeed = left;
	ctrl_vib.wRightMotorSpeed = right;
	XInputSetState(ctrl_ID, &ctrl_vib);
	return;
}

void GamePad::XBoxController::SetDeadzone(unsigned int radius)
{
	if (radius  < 32767) {
		deadzone = radius;
	}
	else if(radius > 32767){
		deadzone = 32767;
	}

	return;
}
