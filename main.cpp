#include <iostream>
#include "Simulator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(760, 660), "Particle Simulation");
    
    Simulator::get_window_ptr(&window);
    Simulator simulator;

    bool in_focus = true,
         running = true;

    while (running)
    {
        sf::Event e;

        while (window.pollEvent(e))
        {
            //Close window if closed or Escape key is pressed while in focus.
            if (e.type == sf::Event::Closed ||
                (in_focus && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                running = false;
            }

            //Adjust window focus if changed.
            if (in_focus && e.type == sf::Event::LostFocus)
                in_focus = false;
            else if (!in_focus && e.type == sf::Event::GainedFocus)
                in_focus = true;
        }

        //Only update and draw to window if it is in focus.
        if (in_focus)
        {
            //DEBUG SPACEBAR SLOW MO
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.setFramerateLimit(10);
            else               //completely reasonable.
                window.setFramerateLimit(9999999);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            simulator.update();
            simulator.draw_simulator();

            window.display();
        }

    }

    return 0;
}
