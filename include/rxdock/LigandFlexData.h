/***********************************************************************
 * The rDock program was developed from 1998 - 2006 by the software team
 * at RiboTargets (subsequently Vernalis (R&D) Ltd).
 * In 2006, the software was licensed to the University of York for
 * maintenance and distribution.
 * In 2012, Vernalis and the University of York agreed to release the
 * program as Open Source software.
 * This version is licensed under GNU-LGPL version 3.0 with support from
 * the University of Barcelona.
 * http://rdock.sourceforge.net/
 ***********************************************************************/

// Manages flexibility data for ligands
#ifndef _RBTLIGANDFLEXDATA_
#define _RBTLIGANDFLEXDATA_

#include "rxdock/FlexData.h"

namespace rxdock {

class LigandFlexData : public FlexData {
public:
  // Translation mutation step length (A)
  static const std::string &_TRANS_STEP;
  // Whole-body orientation mutation step length (deg)
  static const std::string &_ROT_STEP;
  // Dihedral angle mutation step length (deg)
  static const std::string &_DIHEDRAL_STEP;
  // Enum for translation mode (0=FIXED, 1=TETHERED, 2=FREE)
  static const std::string &_TRANS_MODE;
  // Enum for rotation mode (0=FIXED, 1=TETHERED, 2=FREE)
  static const std::string &_ROT_MODE;
  // Enum for dihedral mode (0=FIXED, 1=TETHERED, 2=FREE)
  static const std::string &_DIHEDRAL_MODE;
  // Max allowed distance from initial COM (for tethered translation only)
  static const std::string &_MAX_TRANS;
  // Max allowed rotation from initial orientation
  //(for tethered rotation only)
  static const std::string &_MAX_ROT;
  // Max allowed dihedral rotation from initial dihedrals
  //(for tethered dihedrals only)
  static const std::string &_MAX_DIHEDRAL;

  RBTDLL_EXPORT static const std::string &GetTransMode();
  RBTDLL_EXPORT static const std::string &GetRotMode();

  RBTDLL_EXPORT LigandFlexData(DockingSite *pDockSite);
  virtual void Accept(FlexDataVisitor &v) { v.VisitLigandFlexData(this); }

private:
  LigandFlexData();
};

} // namespace rxdock

#endif //_RBTLIGANDFLEXDATA_
