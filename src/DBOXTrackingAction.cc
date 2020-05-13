#include "DBOXTrackingAction.hh"

#include "DBOXDetectorConstruction.hh"
#include "DBOXRun.hh"
//#include "HistoManager.hh"

#include "G4Track.hh"
#include "G4RunManager.hh"
#include "G4Proton.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DBOXTrackingAction::DBOXTrackingAction(DBOXDetectorConstruction* det)
:G4UserTrackingAction(),fDBOXDetector(det)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DBOXTrackingAction::PostUserTrackingAction(const G4Track* track)
{
 G4int trackID = track->GetTrackID();

 //G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
 DBOXRun* run
   = static_cast<DBOXRun*>(
       G4RunManager::GetRunManager()->GetNonConstCurrentRun());



 //status of primary particle : absorbed, transmited, reflected ?
 //
 if (trackID == 1) {
  G4int status = 0;
  if (!track->GetNextVolume()) {
    if (track->GetMomentumDirection().x() > 0.) status = 1;
    else                                        status = 2;
  }
  run->AddTrackStatus(status);
 }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
