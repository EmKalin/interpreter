#include <iostream>
#include "Interp4Move.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
  Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Move"; }
}


/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}


/*!
 *
 */
// Interp4Move::Interp4Move(): this->_Speed(0)
// {}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  /*
   * \brief Zwraca ostatnią zapisaną komende
   */
  cout << GetCmdName() << " " << this->_MobileObjName  << " " << this->_Speed << " " << this->_PathLength << endl;
}


/*!
 * \brief Zwraca nazwę komendy
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Move::ReadParams(params newParams)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
   this->_MobileObjName = static_cast<string> (newParams["objName"]);
   this->_Speed = stod(static_cast<string>(newParams["Velocity"]));
   this->_PathLength = stod(static_cast<string>(newParams["PathLength"]));
   return true;
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

/*!
 *
 */
void Interp4Move::PrintParams() const
{
  cout << "   Actual PARAMS of " << GetCmdName() << ":" << endl;
  cout << "       -> Selected Mobile Object: " << this->_MobileObjName << endl;
  cout << "       -> Speed: " << this->_Speed << " m/s" << endl;
  cout << "       -> Path length: " << this->_PathLength << " m" << endl;
}
