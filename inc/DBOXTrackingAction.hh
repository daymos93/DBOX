#ifndef DBOXTRACKINGACTION_HH
#define DBOXTRACKINGACTION_HH

#include "G4UserTrackingAction.hh"
#include "globals.hh"

class DBOXDetectorConstruction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DBOXTrackingAction : public G4UserTrackingAction {

  public:  
	DBOXTrackingAction(DBOXDetectorConstruction* det);
   ~DBOXTrackingAction() {};
   
    virtual void PostUserTrackingAction(const G4Track*);

  private:
    DBOXDetectorConstruction* fDBOXDetector;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
