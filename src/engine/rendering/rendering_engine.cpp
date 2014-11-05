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

#include "rendering_engine.h"
#include "../core/transform.h"
#include "../core/math.h"

RenderingEngine::RenderingEngine() :
    m_basicShader("basicShader")
{
	m_basicShader.addUniform("uniformFloat");
	m_basicShader.addUniform("transform");
	m_basicShader.addUniform("viewProjection");
}

void RenderingEngine::render(const Mesh &mesh)
{
	m_basicShader.bind();
    mesh.draw();
}
