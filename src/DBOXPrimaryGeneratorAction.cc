
#include "DBOXPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh" 
#include "G4ParticleTable.hh"
#include "DBOXDetectorConstruction.hh"

DBOXPrimaryGeneratorAction::DBOXPrimaryGeneratorAction(DBOXDetectorConstruction* det)
:   G4VUserPrimaryGeneratorAction(),
    fDBOXDetector(det),
    fParticleGun(nullptr) {
    // create the particle-gun object
    G4int nParticle = 1;
    fParticleGun    = new G4ParticleGun(nParticle);
    SetDefaultKinematic();
}


DBOXPrimaryGeneratorAction::~DBOXPrimaryGeneratorAction() {
    delete fParticleGun;
}


void DBOXPrimaryGeneratorAction::GeneratePrimaries(G4Event* evt) {
	fParticleGun->GeneratePrimaryVertex(evt);
}


void DBOXPrimaryGeneratorAction::SetDefaultKinematic() {
    //
    // default primary particle: 30 [MeV] e- perpendicular to the target
	G4ParticleDefinition* part = G4ParticleTable::GetParticleTable()->FindParticle( "proton" );
    fParticleGun->SetParticleDefinition( part );
    fParticleGun->SetParticleMomentumDirection( G4ThreeVector(1., 0., 0.) );
    fParticleGun->SetParticleEnergy( 20.*CLHEP::MeV );
    UpdatePosition();
}


// needs to be invoked for all workers at the begining of the run: user might 
// have changed the target thickness
void DBOXPrimaryGeneratorAction::UpdatePosition() {
    fParticleGun->SetParticlePosition( 
        G4ThreeVector( fDBOXDetector->GetGunXPosition(), 0.0, 0.0 ) );
}


const G4String& DBOXPrimaryGeneratorAction::GetParticleName() const {
	return fParticleGun->GetParticleDefinition()->GetParticleName();
}


G4double DBOXPrimaryGeneratorAction::GetParticleEnergy() const {
	return fParticleGun->GetParticleEnergy();
}
