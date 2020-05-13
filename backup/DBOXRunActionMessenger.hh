
#ifndef DBOXRUNACTIONMESSENGER_HH
#define DBOXRUNACTIONMESSENGER_HH

#include "G4UImessenger.hh"

// forward declarations
class DBOXRunAction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4String;

class DBOXRunActionMessenger : public G4UImessenger {

  // Method declaration:
  public:

    // CTR & DTR 
	DBOXRunActionMessenger(DBOXRunAction* runAction);
   ~DBOXRunActionMessenger();

    // @Override the base class method
    void SetNewValue(G4UIcommand*, G4String);
  

  // Data member declarations  
  private:

    DBOXRunAction*             fDBOXRunAction;
    
    G4UIdirectory*             fDirCMD;
    G4UIcmdWithAString*        fEdepHistogramCMD;
};

#endif
