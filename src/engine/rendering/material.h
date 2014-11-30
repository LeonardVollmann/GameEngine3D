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

#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include "../core/math.h"

class Material
{
public:
    Material(const Texture &texture, const Vector3f &color) :
        m_texture(texture),
        m_color(color) {}
    
    void bindTexture(unsigned int unit) const;
    
    inline const Texture &getTexture() const { return m_texture; }
    inline const Vector3f &getColor() const { return m_color; }
    
    inline void setTexture(const Texture &texture) { m_texture = texture; }
    inline void setColor(const Vector3f &color) { m_color = color; }
protected:
private:
    Texture m_texture;
    Vector3f m_color;
};

#endif