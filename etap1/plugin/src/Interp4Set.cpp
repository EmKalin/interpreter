#include <iostream>
#include "Interp4Set.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
  Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}


/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
// Interp4Move::Interp4Move(): this->_Speed(0)
// {}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   * \brief Zwraca ostatnią zapisaną komende
   */
  cout << GetCmdName() << " " << this->_MobileObjName  << " " << this->_coorX << " " << this->_coorY << " " << this->_angOZ << endl;
}


/*!
 * \brief Zwraca nazwę komendy
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Set::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Set::ReadParams(params newParams)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
   this->_MobileObjName = static_cast<string>(newParams["objName"]);
   this->_coorX = stod(static_cast<string>(newParams["coorX"]));
   this->_coorY = stod(static_cast<string>(newParams["coorY"]));
   this->_angOZ = stod(static_cast<string>(newParams["angleOZ"]));
   return true;
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  WspolrzednaX[m]  WspolrzednaY[m]  Kat[deg]" << endl;
}

/*!
 *
 */
void Interp4Set::PrintParams() const
{
  cout << "   Actual PARAMS of " << GetCmdName() << ":" << endl;
  cout << "       -> Selected Mobile Object: " << this->_MobileObjName << endl;
  cout << "       -> X coordinate: " << this->_coorX << " m" << endl;
  cout << "       -> Y coordinate: " << this->_coorY << " m" << endl;
  cout << "       -> Angle: " << this->_angOZ << " deg" << endl;
}
