##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=xrm-menu-convert
ConfigurationName      :=Debug
WorkspacePath          := "/home/merc/code/Oblivion2-XRM/linux"
ProjectPath            := "/home/merc/code/Oblivion2-XRM/xrm-menu-convert"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Michae Griffin
Date                   :=20/11/16
CodeLitePath           :="/home/merc/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="xrm-menu-convert.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../src $(IncludeSwitch)../sqlitewrap $(IncludeSwitch)../sqlitewrap/Debug 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)boost_system $(LibrarySwitch)boost_thread $(LibrarySwitch)boost_chrono $(LibrarySwitch)boost_serialization $(LibrarySwitch)boost_locale $(LibrarySwitch)boost_filesystem $(LibrarySwitch)boost_timer $(LibrarySwitch)boost_regex $(LibrarySwitch)SqliteWrapped $(LibrarySwitch)sqlite3 $(LibrarySwitch)pthread $(LibrarySwitch)ssl $(LibrarySwitch)crypto $(LibrarySwitch)yaml-cpp 
ArLibs                 :=  "boost_system" "boost_thread" "boost_chrono" "boost_serialization" "boost_locale" "boost_filesystem" "boost_timer" "boost_regex" "libSqliteWrapped.a" "sqlite3" "pthread" "ssl" "crypto" "yaml-cpp" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)../src $(LibraryPathSwitch)../sqlitewrap $(LibraryPathSwitch)../sqlitewrap/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -Wfatal-errors -g -O0 -pedantic -W -std=c++14 -Wall -Wno-deprecated -Wno-unused-local-typedefs $(Preprocessors)
CFLAGS   :=  -Wfatal-errors -g -O0 -pedantic -W -std=c++14 -Wall -Wno-deprecated -Wno-unused-local-typedefs $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_common_io.cpp$(ObjectSuffix) $(IntermediateDirectory)/data_config_dao.cpp$(ObjectSuffix) $(IntermediateDirectory)/data_menu_dao.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/merc/code/Oblivion2-XRM/xrm-menu-convert/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_common_io.cpp$(ObjectSuffix): ../src/common_io.cpp $(IntermediateDirectory)/src_common_io.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/merc/code/Oblivion2-XRM/src/common_io.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_common_io.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_common_io.cpp$(DependSuffix): ../src/common_io.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_common_io.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_common_io.cpp$(DependSuffix) -MM "../src/common_io.cpp"

$(IntermediateDirectory)/src_common_io.cpp$(PreprocessSuffix): ../src/common_io.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_common_io.cpp$(PreprocessSuffix) "../src/common_io.cpp"

$(IntermediateDirectory)/data_config_dao.cpp$(ObjectSuffix): ../src/data/config_dao.cpp $(IntermediateDirectory)/data_config_dao.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/merc/code/Oblivion2-XRM/src/data/config_dao.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/data_config_dao.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/data_config_dao.cpp$(DependSuffix): ../src/data/config_dao.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/data_config_dao.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/data_config_dao.cpp$(DependSuffix) -MM "../src/data/config_dao.cpp"

$(IntermediateDirectory)/data_config_dao.cpp$(PreprocessSuffix): ../src/data/config_dao.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/data_config_dao.cpp$(PreprocessSuffix) "../src/data/config_dao.cpp"

$(IntermediateDirectory)/data_menu_dao.cpp$(ObjectSuffix): ../src/data/menu_dao.cpp $(IntermediateDirectory)/data_menu_dao.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/merc/code/Oblivion2-XRM/src/data/menu_dao.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/data_menu_dao.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/data_menu_dao.cpp$(DependSuffix): ../src/data/menu_dao.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/data_menu_dao.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/data_menu_dao.cpp$(DependSuffix) -MM "../src/data/menu_dao.cpp"

$(IntermediateDirectory)/data_menu_dao.cpp$(PreprocessSuffix): ../src/data/menu_dao.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/data_menu_dao.cpp$(PreprocessSuffix) "../src/data/menu_dao.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


