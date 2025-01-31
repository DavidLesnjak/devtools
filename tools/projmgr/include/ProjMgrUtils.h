/*
 * Copyright (c) 2020-2022 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PROJMGRUTILS_H
#define PROJMGRUTILS_H

#include "ProjMgrKernel.h"
#include "ProjMgrParser.h"

 /**
 * @brief vector of ConnectItem pointers
 */
typedef std::vector<const ConnectItem*> ConnectPtrVec;

/**
 * @brief connections collection item containing
 *        filename pointer
 *        layer type pointer
 *        vector of ConnectItem pointers
 *        copy assignment operator
*/
struct ConnectionsCollection {
  const std::string& filename;
  const std::string& type;
  ConnectPtrVec connections;
  ConnectionsCollection& operator=(const ConnectionsCollection& c) { return *this; };
};

/**
 * @brief output type item containing
 *        on boolean
 *        string filename
*/
struct OutputType {
  bool on;
  std::string filename;
};

/**
 * @brief output types item containing
 *        bin output type
 *        elf output type
 *        hex output type
 *        lib output type
 *        cmse output type
*/
struct OutputTypes {
  OutputType bin;
  OutputType elf;
  OutputType hex;
  OutputType lib;
  OutputType cmse;
};

/**
 * @brief vector of ConnectionsCollection
*/
typedef std::vector<ConnectionsCollection> ConnectionsCollectionVec;

/**
 * @brief map of ConnectionsCollection
*/
typedef std::map<std::string, ConnectionsCollectionVec> ConnectionsCollectionMap;

/**
  * @brief string pair
 */
typedef std::pair<std::string, std::string> StrPair;

/**
 * @brief string vector
*/
typedef std::vector<std::string> StrVec;

/**
 * @brief string set
*/
typedef std::set<std::string> StrSet;

/**
 * @brief vector of string pair
*/
typedef std::vector<StrPair> StrPairVec;

/**
 * @brief vector of string pair pointer
*/
typedef std::vector<const StrPair*> StrPairPtrVec;

/**
 * @brief map of string vector
*/
typedef std::map<std::string, StrVec> StrVecMap;

/**
 * @brief map of int
*/
typedef std::map<std::string, int> IntMap;

/**
 * @brief map of string
*/
typedef std::map<std::string, std::string> StrMap;

/**
 * @brief projmgr utils class
*/
class ProjMgrUtils {
public:

  typedef std::pair<std::string, int> Result;

  /**
   * @brief component and pack delimiters
  */
  static constexpr const char* COMPONENT_DELIMITERS = ":&@";
  static constexpr const char* SUFFIX_CVENDOR = "::";
  static constexpr const char* PREFIX_CBUNDLE = "&";
  static constexpr const char  PREFIX_CBUNDLE_CHAR = '&';
  static constexpr const char* PREFIX_CGROUP = ":";
  static constexpr const char* PREFIX_CSUB = ":";
  static constexpr const char* PREFIX_CVARIANT = "&";
  static constexpr const char  PREFIX_CVARIANT_CHAR = '&';
  static constexpr const char* PREFIX_CVERSION = "@";
  static constexpr const char  PREFIX_CVERSION_CHAR = '@';
  static constexpr const char* SUFFIX_PACK_VENDOR = "::";
  static constexpr const char* PREFIX_PACK_VERSION = "@";

  /**
   * @brief output types
  */
  static constexpr const char* OUTPUT_TYPE_BIN = "bin";
  static constexpr const char* OUTPUT_TYPE_ELF = "elf";
  static constexpr const char* OUTPUT_TYPE_HEX = "hex";
  static constexpr const char* OUTPUT_TYPE_LIB = "lib";
  static constexpr const char* OUTPUT_TYPE_CMSE = "cmse-lib";

  /**
   * @brief access sequences
  */
  static constexpr const char* AS_SOLUTION = "Solution";
  static constexpr const char* AS_PROJECT = "Project";
  static constexpr const char* AS_COMPILER = "Compiler";
  static constexpr const char* AS_BUILD_TYPE = "BuildType";
  static constexpr const char* AS_TARGET_TYPE = "TargetType";
  static constexpr const char* AS_DNAME = "Dname";
  static constexpr const char* AS_PNAME = "Pname";
  static constexpr const char* AS_BNAME = "Bname";

  static constexpr const char* AS_SOLUTION_DIR = "SolutionDir";
  static constexpr const char* AS_PROJECT_DIR = "ProjectDir";
  static constexpr const char* AS_OUT_DIR = "OutDir";
  static constexpr const char* AS_BIN = OUTPUT_TYPE_BIN;
  static constexpr const char* AS_ELF = OUTPUT_TYPE_ELF;
  static constexpr const char* AS_HEX = OUTPUT_TYPE_HEX;
  static constexpr const char* AS_LIB = OUTPUT_TYPE_LIB;
  static constexpr const char* AS_CMSE = OUTPUT_TYPE_CMSE;

  /**
   * @brief default and toolchain specific output affixes
  */
  static constexpr const char* DEFAULT_ELF_SUFFIX = ".elf";
  static constexpr const char* DEFAULT_LIB_PREFIX = "";
  static constexpr const char* DEFAULT_LIB_SUFFIX = ".a";

  static constexpr const char* AC6_ELF_SUFFIX = ".axf";
  static constexpr const char* GCC_ELF_SUFFIX = ".elf";
  static constexpr const char* IAR_ELF_SUFFIX = ".out";
  static constexpr const char* AC6_LIB_PREFIX = "";
  static constexpr const char* GCC_LIB_PREFIX = "lib";
  static constexpr const char* IAR_LIB_PREFIX = "";
  static constexpr const char* AC6_LIB_SUFFIX = ".lib";
  static constexpr const char* GCC_LIB_SUFFIX = ".a";
  static constexpr const char* IAR_LIB_SUFFIX = ".a";

  /**
   * @brief class constructor
  */
  ProjMgrUtils(void);

  /**
   * @brief class destructor
  */
  ~ProjMgrUtils(void);

  /**
   * @brief get fully specified component identifier
   * @param rte component
   * @return string component identifier
  */
  static std::string GetComponentID(const RteItem* component);

  /**
   * @brief get fully specified condition identifier
   * @param rte condition
   * @return string condition identifier
  */
  static std::string GetConditionID(const RteItem* condition);

  /**
   * @brief get fully specified component aggregate identifier
   * @param rte component aggregate
   * @return string component aggregate identifier
  */
  static std::string GetComponentAggregateID(const RteItem* component);

  /**
   * @brief get partial component identifier (without vendor and version)
   * @param rte component
   * @return string partial component identifier
  */
  static std::string GetPartialComponentID(const RteItem* component);

  /**
   * @brief get component attributes from supplied component ID
   * @param componentId component id string
   * @return map of key-value pairs of componentAttributes
  */
  static std::map<std::string, std::string> ComponentAttributesFromId(const std::string& componentId);

  /**
   * @brief get fully specified package identifier
   * @param rte package
   * @return string package identifier
  */
  static std::string GetPackageID(const RteItem* pack);
  static std::string GetPackageID(const std::string& vendor, const std::string& name, const std::string& version);

  /**
   * @brief read gpdsc file
   * @param path to gpdsc file
   * @param pointer to rte generator model
   * @param reference to validation result
   * @return pointer to created RtePackage if successful, nullptr otherwise
  */
  static RtePackage* ReadGpdscFile(const std::string& gpdsc, bool& valid);

  /**
   * @brief execute shell command
   * @param cmd string shell command to be executed
   * @return command execution result <string, error_code>
  */
  static const Result ExecCommand(const std::string& cmd);

  /**
   * @brief get file category according to file extension
   * @param filename with extension
   * @return string category
  */
  static const std::string GetCategory(const std::string& file);

  /**
   * @brief add a value into a vector/list if it does not already exist in the vector/list
   * @param vec/list the vector/list to add the value into
   * @param value the value to add
  */
  static void PushBackUniquely(std::vector<std::string>& vec, const std::string& value);
  static void PushBackUniquely(std::list<std::string>& lst, const std::string& value);
  static void PushBackUniquely(StrPairVec& vec, const StrPair& value);

  /**
   * @brief convert string to int, return 0 if it's empty or not convertible
   * @param string
   * @return int
  */
  static int StringToInt(const std::string& value);

  /**
   * @brief expand compiler id the format <name>@[>=]<version> into name, minimum and maximum versions
   * @param compiler id
   * @param name reference to compiler name
   * @param minVer reference to compiler minimum version
   * @param maxVer reference to compiler maximum version
  */
  static void ExpandCompilerId(const  std::string& compiler, std::string& name, std::string& minVer, std::string& maxVer);

  /**
   * @brief check if compilers are compatible in the format <name>@[>=]<version>
   * @param first compiler id
   * @param second compiler id
   * @return true if compilers are compatible, false otherwise
  */
  static bool AreCompilersCompatible(const std::string& first, const std::string& second);

  /**
   * @brief get compilers version range intersection in the format <name>@[>=]<version>
   * @param first compiler id
   * @param second compiler id
   * @param intersection reference to intersection id
  */
  static void CompilersIntersect(const std::string& first, const std::string& second, std::string& intersection);

  /**
   * @brief get compiler root
   * @param compilerRoot reference 
  */
  static void GetCompilerRoot(std::string& compilerRoot);

  /**
   * @brief parse context entry
   * @param contextEntry string in the format <project-name>.<build-type>+<target-type>
   * @return ContextName structure with project name, build type and target type strings
  */
  static ContextName ParseContextEntry(const std::string& contextEntry);

  /**
   * @brief set output type
   * @param typeString string with output type
   * @param type reference to OutputTypes structure
  */
  static void SetOutputType(const std::string typeString, OutputTypes& type);

protected:
  static std::string ConstructID(const std::vector<std::pair<const char*, const std::string&>>& elements);
};

#endif  // PROJMGRUTILS_H
