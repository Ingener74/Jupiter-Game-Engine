
#if defined(SWIGPYTHON)
    %module(directors="1") PyJupiter
#elif defined(SWIGLUA)
    %module(directors="1") LuaJupiter
#else
    #warning no tupemaps
#endif

%{

#include "Jupiter/JupiterError.h"
#include "Jupiter/LinuxFileFactory.h"
#include "Jupiter/File.h"
#include "Jupiter/Game.h"
#include "Jupiter/JsonGame.h"
#include "Jupiter/Sprite.h"
#include "Jupiter/Node.h"
#include "Jupiter/Controller.h"
#include "Jupiter/Image.h"
#include "Jupiter/Texture.h"

using namespace jupiter;

%}

%include "std_string.i"
%include "std_vector.i"

#include "Jupiter/JupiterError.h"
#include "Jupiter/File.h"
#include "Jupiter/LinuxFileFactory.h"
#include "Jupiter/Game.h"
#include "Jupiter/JsonGame.h"
#include "Jupiter/Node.h"
#include "Jupiter/Sprite.h"
#include "Jupiter/Controller.h"
