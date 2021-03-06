/*
 * Copyright (c) 2014 Leonard Vollmann
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include "transform.h"
#include "../rendering/camera.h"
#include "../rendering/rendering_engine.h"

class CoreEngine;

class Game
{
public:
    Game() {}
    virtual ~Game() {}
    
    virtual void init() = 0;

	virtual void processInput(Input &input)
	{
		m_root.processInputAll(input);
	}

	virtual void update(float delta)
	{
		m_root.updateAll(delta);
	}

	virtual void render(RenderingEngine *renderingEngine)
	{
		renderingEngine->render(m_root);
	}

	virtual inline void add(Entity *entity)
	{
		m_root.addChild(entity);
	}

	inline void setEngine(CoreEngine *engine) { m_engine = engine; }
protected:
	CoreEngine *m_engine;

	Entity m_root;
private:
};

#endif
