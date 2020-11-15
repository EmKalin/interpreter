#include <iostream>
#include "Interp4Pause.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
  Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Pause"; }
}


/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}


/*!
 *
 */
// Interp4Move::Interp4Move(): this->_Speed(0)
// {}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
  /*
   * \brief Zwraca ostatnią zapisaną komende
   */
  cout << GetCmdName() << " " << this->_pauseTime  << endl;
}


/*!
 * \brief Zwraca nazwę komendy
 */
const char* Interp4Pause::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Pause::ExecCmd( MobileObj  *pMobObj,  int  Socket) const
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}


/*!
 *
 */
bool Interp4Pause::ReadParams(params newParams)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
   this->_pauseTime = stod(static_cast<string>(newParams["pauseTime"]));
   return true;
}


/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  Czas[ms]" << endl;
}

/*!
 *
 */
void Interp4Pause::PrintParams() const
{
  cout << "   Actual PARAMS of " << GetCmdName() << ":" << endl;
  cout << "       -> Pause Time: " << this->_pauseTime << endl;

}
