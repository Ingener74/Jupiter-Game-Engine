/*
 * GamePlayer.h
 *
 *  Created on: Mar 25, 2015
 *      Author: pavel
 */

#ifndef APPS_GAMEPLAYER_SRC_GAMEPLAYER_H_
#define APPS_GAMEPLAYER_SRC_GAMEPLAYER_H_

#include <map>
#include <memory>
#include <fstream>
#include <iterator>
#include <iostream>
#include <stdexcept>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GL/glew.h>

bool myCreateGame(int argc, char* argv[]);
bool myCreateGameWithJsonFile(int argc, char* argv[]);
void myDraw();
void myInput();

std::string getTitle();
int getWidth();
int getHeight();

#endif /* APPS_GAMEPLAYER_SRC_GAMEPLAYER_H_ */
