
#include "DBOXRunAction.hh"

#include "DBOXDetectorConstruction.hh"
#include "DBOXPrimaryGeneratorAction.hh"
#include "DBOXRun.hh"
#include "G4Run.hh"
//#include "DBOXRunActionMessenger.hh"

#include "Randomize.hh"


DBOXRunAction::DBOXRunAction(DBOXDetectorConstruction* det, DBOXPrimaryGeneratorAction* prim)
:   G4UserRunAction(),
    fDBOXDetector(det),
    fDBOXPrimary(prim),
    fDBOXRun(nullptr) { }
//    fIsEdepHistogramUICmdInvoked(false) {
  /* histo manager could be created here */ 
  // Create our own UI messenger object that will interact to this Run-Action
  // to set some properties that will be used to update DBOXRun object (generated
  // by calling this Run-Action::GenerateRun method) in the BeginOfRunAction method.
//  fMessenger = new DBOXRunActionMessenger(this);
//}

DBOXRunAction::~DBOXRunAction() {
  /* histo manager must be deleted here then*/ 
  // delete all dynamically allocated objects here 
//  delete fMessenger;
}


G4Run* DBOXRunAction::GenerateRun() {
	fDBOXRun = new DBOXRun(fDBOXDetector, fDBOXPrimary);
	return fDBOXRun;
}


void DBOXRunAction::BeginOfRunAction(const G4Run* /*run*/) {
    // Show Rndm status (only for the Master thread)
//    if ( IsMaster() ) G4Random::showEngineStatus();
    //
    // Make sure that the Gun position is correct: the user can change the target
    // thickness between construction of objects and start of the run.  
    // note: primary generator is set in the CTR only for the Worker threads in the 
    //       ActionInitialization (left null for Master in the BuildForMaster())
    if ( fDBOXPrimary ) {
        fDBOXPrimary->UpdatePosition();
    }
    // Update the properties of the Energy-deposit histogram member of DBOXRun,
    // that is already available at this point: Only if the user invoked the UI 
    // command /DBOXApp/runAction/edepHistoto set properties of the Edep-histo.
//    if ( fIsEdepHistogramUICmdInvoked ) {
      // user defined the properties of the Edep-histo by invoking the UI command 
//      fDBOXRun->SetEdepHisto(fEdepHistFileName, fEdepHistMinEnergy,
//                             fEdepHistMaxEnergy, fEdepHistNumBins);
//    }
    //
    // G4AnalysisManager* analysisManager OpenFile
}


void DBOXRunAction::EndOfRunAction(const G4Run*) {
    // Print Run summary (only for the Master thread)
    if ( IsMaster() ) { 
    	fDBOXRun->EndOfRunSummary();
    }
    //
    // Show Rndm status (only for the Master thread)
//    if ( IsMaster() ) G4Random::showEngineStatus();
	//
	// G4AnalysisManager* analysisManager Write and CloseFile
}

