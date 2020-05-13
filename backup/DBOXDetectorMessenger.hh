// A UI messenger class that implements our own UI commands to manipulate some 
// properties (thickness, material) of the detector Target. An object from this 
// class must be created and stored in the coresponding YourDetectorConstruction
// object on which the implemented/defined commands will act.
#ifndef DBOXDETECTORMESSENGER_HH
#define DBOXDETECTORMESSENGER_HH

#include "G4UImessenger.hh"

// forward declarations
class DBOXDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAString;
class G4String;

class DBOXDetectorMessenger : public G4UImessenger {

  // Method declaration:
  public:

    // CTR & DTR 
	DBOXDetectorMessenger(DBOXDetectorConstruction* det);
   ~DBOXDetectorMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);
  

  // Data member declarations  
  private:

    DBOXDetectorConstruction*  fDBOXDetector;
    
    G4UIdirectory*             fDirCMD;
    G4UIcmdWithADoubleAndUnit* fTargetThicknessCMD;
    G4UIcmdWithAString*        fTargetMaterialCMD;

};

#endif
