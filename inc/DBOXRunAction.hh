
#ifndef DBOXRUNACTION_HH
#define DBOXRUNACTION_HH

#include "G4UserRunAction.hh"

#include "G4String.hh"

// forward declarations
class DBOXDetectorConstruction;
class DBOXPrimaryGeneratorAction;
class DBOXRun;
class G4Run;
//class DBOXRunActionMessenger;


class DBOXRunAction : public G4UserRunAction {

  // Method declaration:
  public:
    
    // CTR: 
    //  - detector construction object is used in the stepping action to check target
    //  - primary generator is used to re-set position for workers and to get E0 (set only for workers)
    DBOXRunAction(DBOXDetectorConstruction* det, DBOXPrimaryGeneratorAction* prim = nullptr);
    virtual ~DBOXRunAction();

    
    // Virtual method to generate DBOXRun for each Worker threads
    virtual G4Run* GenerateRun();    

    // Virtial method that is called by the RunManager before the first event starts
    virtual void   BeginOfRunAction(const G4Run*);

    // Virtual method that is called by the RunManager after the last event finished
    virtual void   EndOfRunAction(const G4Run*);

    // Public method to activate and set properties to the energy deposit histogram
    // member of DBOXRun object(s). Note, that DBOXRun objects will be created
    // when the G4RunManager(s) and G4MTRunManager invokes the GenerateRun() method 
    // of their thraed local object of this RunAction class. Since these DBOXRun
    // objects, together with their Energy-deposit histogram members, will be 
    // available only after that point, we need to keep all the histogram 
    // properties here, in the RunAction class, that is available before (see more 
    // below at the fMessenger declaration) and propagate all proprties to the 
    // Energy deposit histogram member of DBOXRun in the BeginOfRunAction when
    // all those objects are already available.
    //void SetEdepHistogram(const G4String& filename, G4double emin, G4double emax,
    //                      G4int numbins) {
    //    fIsEdepHistogramUICmdInvoked = true;
    //    fEdepHistFileName  = filename;
    //    fEdepHistMinEnergy = emin;
    //    fEdepHistMaxEnergy = emax;
    //    fEdepHistNumBins   = numbins;
    //}


  // Data member declarations:
  private:

  	DBOXDetectorConstruction*    fDBOXDetector;

  	DBOXPrimaryGeneratorAction*  fDBOXPrimary;

    DBOXRun*                     fDBOXRun;
    
    // Store Edep-Histogram properties of DBOXRun here and reset at the begining
    // of the run.
    //
    // Note, that DBOXRun object is not available before the GenerateRun method
    // of this DBOXRunAction is invoked by the G4RunManager or G4MTRunManager.
    // On the same time, one DBOXRunAction object is created immediately when the
    // ActionInitialization is registered in the RunManager (in the main) by 
    // calling immediately either the ActionInitialization::BuildForMaster (in 
    // case of MT Geant4) or ActionInitialization::Build (in case of sequential 
    // Geant4) interface method.
    // Therefore, we need to communicate (by UI command) the histogram information 
    // to and store in the RunAction object. Then all the information will be used 
    // to update the corresponding histogram in the BeginOfRunAction method when 
    // DBOXRun object(s) is(are) already available(created) together with their
    // histogram objects.
    //DBOXRunActionMessenger*     fMessenger;
    
    // See the description at the SetEdepHistogram method above.
    //G4bool      fIsEdepHistogramUICmdInvoked;
    //G4String    fEdepHistFileName;
    //G4double    fEdepHistMinEnergy;
    //G4double    fEdepHistMaxEnergy;
    //G4int       fEdepHistNumBins;
    
};

#endif
