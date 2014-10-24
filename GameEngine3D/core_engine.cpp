//
//  core_engine.cpp
//  GameEngine3D
//
//  Created by Leonard Vollmann on 24/10/14.
//  Copyright (c) 2014 Leonard Vollmann. All rights reserved.
//

#include "core_engine.h"
#include "time.h"

#include <iostream>

CoreEngine::CoreEngine(double fps, Window *window) :
    m_frameTime(1.0 / fps),
    m_running(false),
    m_window(window)
{}

void CoreEngine::start()
{
    m_running = true;
    
    unsigned int frames = 0;
    double frameCounterTime = 0;
    double time_0 = Time::getTime();
    double time_1;
    double delta;
    double unprocessed = 0.0;
    while (m_running) {
        if (m_window->isClosed()) {
            stop();
            continue;
        }
        
        time_1 = Time::getTime();
        delta = time_1 - time_0;
        time_0 = time_1;
        
        unprocessed += delta;
        frameCounterTime += delta;
        
        while (unprocessed >= m_frameTime) {
            unprocessed -= m_frameTime;
            
            update();
        }

        if (frameCounterTime >= 1) {
            std::cout << 1000.0 / frames << " ms (" << frames << " fps)" << std::endl;
            
            frameCounterTime = 0;
            frames = 0;
        }
        
        render();
        frames++;
    }
}

void CoreEngine::stop()
{
    m_running = false;
}

void CoreEngine::update()
{

}

void CoreEngine::render()
{
    m_window->update();
}