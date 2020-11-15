#include <iostream>
#include "Interp4Rotate.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
  Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}


/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
// Interp4Move::Interp4Move(): this->_Speed(0)
// {}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  /*
   * \brief Zwraca ostatnią zapisaną komende
   */
  cout << GetCmdName() << " " << this->_MobileObjName  << " " << this->_angSpeed << " " << this->_angle << endl;
}


/*!
 * \brief Zwraca nazwę komendy
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(params newParams)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
   this->_MobileObjName = static_cast<string>(newParams["objName"]);
   this->_angSpeed = stod(static_cast<string>(newParams["angVelocity"]));
   this->_angle = stod(static_cast<string>(newParams["angle"]));
   return true;
}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  Szybkosc katowa[deg/s]  Kat[deg]" << endl;
}

/*!
 *
 */
void Interp4Rotate::PrintParams() const
{
  cout << "   Actual PARAMS of " << GetCmdName() << ":" << endl;
  cout << "       -> Selected Mobile Object: " << this->_MobileObjName << endl;
  cout << "       -> Angular Speed: " << this->_angSpeed << " deg/s" << endl;
  cout << "       -> Angle: " << this->_angle << " deg" << endl;
}
