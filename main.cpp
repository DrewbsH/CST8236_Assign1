#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TransformNode.h"

int main(int argc, char* argv)
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "WindyMills");

	//Creating windmill 1 shapes
	sf::RectangleShape windmill1Base(sf::Vector2<float>(15.0f, 40.0f));
	sf::RectangleShape windmill1BladeNorth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill1BladeEast(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill1BladeSouth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill1BladeWest(sf::Vector2<float>(7.0f, 25.0f));

	//Creating windmill 2 shapes
	sf::RectangleShape windmill2Base(sf::Vector2<float>(15.0f, 40.0f));
	sf::RectangleShape windmill2BladeNorth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill2BladeEast(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill2BladeSouth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill2BladeWest(sf::Vector2<float>(7.0f, 25.0f));

	//Creating windmill 3 shapes
	sf::RectangleShape windmill3Base(sf::Vector2<float>(15.0f, 40.0f));
	sf::RectangleShape windmill3BladeNorth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill3BladeEast(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill3BladeSouth(sf::Vector2<float>(7.0f, 25.0f));
	sf::RectangleShape windmill3BladeWest(sf::Vector2<float>(7.0f, 25.0f));


	sf::Event evt;

	sf::Texture bases;
	sf::Texture background;
	sf::Texture blades;

	//Loading the texture images
	background.loadFromFile("Resources/vector-wavy-rainbow-background.jpg");
	bases.loadFromFile("Resources/wood-pattern-vector.png");
	blades.loadFromFile("Resources/FreeVector-Crossed-Swords.png");

	//Enables the background to repeat itself
	background.setRepeated(true);

	/* Tiling sprite */
	sf::Sprite backSprite;
	backSprite.setTexture(background);
	backSprite.setScale(1.25f, 1.25f);
	// We tell the sprite that it's going to draw the cloud texture at the size of our window.
	backSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

	sf::IntRect backgroundRect = backSprite.getTextureRect();
	//Windmill 1: Setting up the textures
	windmill1Base.setTexture(&bases);
	windmill1BladeNorth.setTexture(&blades, true);
	windmill1BladeEast.setTexture(&blades, true);
	windmill1BladeSouth.setTexture(&blades, true);
	windmill1BladeWest.setTexture(&blades, true);

	//Windmill 2: Setting up the textures
	windmill2Base.setTexture(&bases);
	windmill2BladeNorth.setTexture(&blades, true);
	windmill2BladeEast.setTexture(&blades, true);
	windmill2BladeSouth.setTexture(&blades, true);
	windmill2BladeWest.setTexture(&blades, true);

	//Windmill 3: Setting up the textures
	windmill3Base.setTexture(&bases);
	windmill3BladeNorth.setTexture(&blades, true);
	windmill3BladeEast.setTexture(&blades, true);
	windmill3BladeSouth.setTexture(&blades, true);
	windmill3BladeWest.setTexture(&blades, true);

	//Boolean variables for which key is pressed
	bool keyHeld = false;
	bool key1 = false;
	bool key2 = false;
	bool key3 = false;
	bool key4OrA = true;


	//angles
	float bladeAngleAmount = 200.0f;
	float bodyAngleAmount = 400.0f;

	//Windmill 1: Setting up base
	windmill1Base.setOrigin((windmill1Base.getLocalBounds().width * 0.5), windmill1Base.getLocalBounds().height * 0.5);
	windmill1Base.setPosition(300.0f, 375.0f);
	windmill1Base.setScale(4, 4);

	//Windmill 2: Setting up base
	windmill2Base.setOrigin((windmill2Base.getLocalBounds().width * 0.5), windmill2Base.getLocalBounds().height * 0.5);
	windmill2Base.setPosition(600.0f, 375.0f);
	windmill2Base.setScale(4, 4);

	//Windmill 3: Setting up base
	windmill3Base.setOrigin((windmill3Base.getLocalBounds().width * 0.5), windmill3Base.getLocalBounds().height * 0.5);
	windmill3Base.setPosition(900.0f, 375.0f);
	windmill3Base.setScale(4, 4);


	//Windmill 1 blade positions
	windmill1BladeNorth.setPosition(windmill1Base.getLocalBounds().width * 0.5, 5.0);
	windmill1BladeEast.setPosition(windmill1Base.getLocalBounds().width * 0.5, 5.0);
	windmill1BladeSouth.setPosition(windmill1Base.getLocalBounds().width * 0.5, 5.0);
	windmill1BladeWest.setPosition(windmill1Base.getLocalBounds().width * 0.5, 5.0);

	//Windmill 2 blade positions
	windmill2BladeNorth.setPosition(windmill2Base.getLocalBounds().width * 0.5, 5.0);
	windmill2BladeEast.setPosition(windmill2Base.getLocalBounds().width * 0.5, 5.0);
	windmill2BladeSouth.setPosition(windmill2Base.getLocalBounds().width * 0.5, 5.0);
	windmill2BladeWest.setPosition(windmill2Base.getLocalBounds().width * 0.5, 5.0);

	//Windmill 3 blade positions
	windmill3BladeNorth.setPosition(windmill3Base.getLocalBounds().width * 0.5, 5.0);
	windmill3BladeEast.setPosition(windmill3Base.getLocalBounds().width * 0.5, 5.0);
	windmill3BladeSouth.setPosition(windmill3Base.getLocalBounds().width * 0.5, 5.0);
	windmill3BladeWest.setPosition(windmill3Base.getLocalBounds().width * 0.5, 5.0);

	//Windmill 1 blade rotations
	windmill1BladeNorth.rotate(0);
	windmill1BladeEast.rotate(90);
	windmill1BladeSouth.rotate(180);
	windmill1BladeWest.rotate(270);

	//Windmill 2 blade rotations
	windmill2BladeNorth.rotate(0);
	windmill2BladeEast.rotate(90);
	windmill2BladeSouth.rotate(180);
	windmill2BladeWest.rotate(270);

	//Windmill 3 blade rotations
	windmill3BladeNorth.rotate(0);
	windmill3BladeEast.rotate(90);
	windmill3BladeSouth.rotate(180);
	windmill3BladeWest.rotate(270);

	//Windmill 1 TransformNodes
	TransformNode windmill1BaseTrans(&windmill1Base);
	TransformNode windmill1BladeEastTrans(&windmill1BladeEast);
	TransformNode windmill1BladeNorthTrans(&windmill1BladeNorth);
	TransformNode windmill1BladeWestTrans(&windmill1BladeWest);
	TransformNode windmill1BladeSouthTrans(&windmill1BladeSouth);

	//Windmill 2 TransformNodes
	TransformNode windmill2BaseTrans(&windmill2Base);
	TransformNode windmill2BladeEastTrans(&windmill2BladeEast);
	TransformNode windmill2BladeNorthTrans(&windmill2BladeNorth);
	TransformNode windmill2BladeWestTrans(&windmill2BladeWest);
	TransformNode windmill2BladeSouthTrans(&windmill2BladeSouth);

	//Windmill 3 TransformNodes
	TransformNode windmill3BaseTrans(&windmill3Base);
	TransformNode windmill3BladeEastTrans(&windmill3BladeEast);
	TransformNode windmill3BladeNorthTrans(&windmill3BladeNorth);
	TransformNode windmill3BladeWestTrans(&windmill3BladeWest);
	TransformNode windmill3BladeSouthTrans(&windmill3BladeSouth);

	//Windmill 1 adding the blades as children of base
	windmill1BaseTrans.AddChild(&windmill1BladeNorthTrans);
	windmill1BaseTrans.AddChild(&windmill1BladeEastTrans);
	windmill1BaseTrans.AddChild(&windmill1BladeSouthTrans);
	windmill1BaseTrans.AddChild(&windmill1BladeWestTrans);

	//Windmill 2 adding the blades as children of base
	windmill2BaseTrans.AddChild(&windmill2BladeNorthTrans);
	windmill2BaseTrans.AddChild(&windmill2BladeEastTrans);
	windmill2BaseTrans.AddChild(&windmill2BladeSouthTrans);
	windmill2BaseTrans.AddChild(&windmill2BladeWestTrans);

	//Windmill 3 adding the blades as children of base
	windmill3BaseTrans.AddChild(&windmill3BladeNorthTrans);
	windmill3BaseTrans.AddChild(&windmill3BladeEastTrans);
	windmill3BaseTrans.AddChild(&windmill3BladeSouthTrans);
	windmill3BaseTrans.AddChild(&windmill3BladeWestTrans);



	float secondTimer = 0.0f; // elapsed time per second.
	float movementSpeed = 150.0f; // scrolling movement speed.

	sf::SoundBuffer askHand;
	askHand.loadFromFile("Resources/ask_mr_hat.wav");
	sf::SoundBuffer smack;
	smack.loadFromFile("Resources/smack.wav");
	sf::SoundBuffer dirtyApe;
	dirtyApe.loadFromFile("Resources/planet_apes_dirty_ape.wav");
	sf::SoundBuffer sharknado;
	sharknado.loadFromFile("Resources/sharknado_throw_bombs.wav");
	sf::SoundBuffer bueler;
	bueler.loadFromFile("Resources/life_moves_fast.wav");
	sf::Sound sound;
	sound.setBuffer(askHand);
	sound.play();

	sf::Transform tranformWind1;
	sf::Transform tranformWind2;
	sf::Transform tranformWind3;

	sf::Clock appTimer;
	sf::Vector2i lastMousePosition = sf::Mouse::getPosition(window);
	while (window.isOpen())
	{
		float deltaTIme = appTimer.restart().asSeconds();

		float centerRotationMovement = 200.0f * deltaTIme;
		//Windmill 1: blade rotations
		windmill1BladeNorth.rotate(bladeAngleAmount * deltaTIme);
		windmill1BladeEast.rotate(bladeAngleAmount * deltaTIme);
		windmill1BladeSouth.rotate(bladeAngleAmount * deltaTIme);
		windmill1BladeWest.rotate(bladeAngleAmount * deltaTIme);

		// Windmill 2: blade rotations
		windmill2BladeNorth.rotate(bladeAngleAmount * deltaTIme);
		windmill2BladeEast.rotate(bladeAngleAmount * deltaTIme);
		windmill2BladeSouth.rotate(bladeAngleAmount * deltaTIme);
		windmill2BladeWest.rotate(bladeAngleAmount * deltaTIme);

		// Windmill 3: blade rotations
		windmill3BladeNorth.rotate(bladeAngleAmount * deltaTIme);
		windmill3BladeEast.rotate(bladeAngleAmount * deltaTIme);
		windmill3BladeSouth.rotate(bladeAngleAmount * deltaTIme);
		windmill3BladeWest.rotate(bladeAngleAmount * deltaTIme);



		//Setting your variables that will deal with mouse movement
		int deltaX = 0;
		int deltaY = 0;



		sf::Event sfEvent;
		while (window.pollEvent(evt))
		{
			//Switch case that determines what type of event has happened.
			switch (evt.type){

				//If a button on the keyboard was pressed this picks up which key was pressed of the available options
			case sf::Event::KeyPressed:
				keyHeld = true;
				if (evt.key.code == sf::Keyboard::Key::Num1 || evt.key.code == sf::Keyboard::Key::Numpad1)
				{
					key1 = true;
					key2 = false;
					key3 = false;
					key4OrA = false;

				}
				else if (evt.key.code == sf::Keyboard::Key::Num2 || evt.key.code == sf::Keyboard::Key::Numpad2)
				{
					key1 = false;
					key2 = true;
					key3 = false;
					key4OrA = false;
				}
				else if (evt.key.code == sf::Keyboard::Key::Num3 || evt.key.code == sf::Keyboard::Key::Numpad3)
				{
					key1 = false;
					key2 = false;
					key3 = true;
					key4OrA = false;
				}
				else if (evt.key.code == sf::Keyboard::Key::Num4 || evt.key.code == sf::Keyboard::Key::Numpad4 || evt.key.code == sf::Keyboard::Key::A)
				{
					key1 = false;
					key2 = false;
					key3 = false;
					key4OrA = true;


					// reset rotations of the windmill
					windmill1Base.setRotation(0.0f);
					windmill2Base.setRotation(0.0f);
					windmill3Base.setRotation(0.0f);

					// reset the transforms of the windmills
					tranformWind1 = sf::Transform::Identity;
					tranformWind2 = sf::Transform::Identity;
					tranformWind3 = sf::Transform::Identity;
				}
				break;


				//Event when a key is released from being held
			case sf::Event::KeyReleased:
				keyHeld = false;
				if (key1)
				{
					sound.setBuffer(sharknado);
					sound.play();
				}
				else if (key2)
				{
					sound.setBuffer(bueler);
					sound.play();
				}
				else if (key3)
				{

					sound.setBuffer(dirtyApe);
					sound.play();
				}
				else if (key4OrA)
				{
					sound.setBuffer(smack);
					sound.play();

				}
				break;


				//Event when a mouse movement happened
			case sf::Event::MouseMoved:
			{
										  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

										  //Used to get the difference between the last position of the mouse
										  deltaX = mousePosition.x - lastMousePosition.x;
										  deltaY = mousePosition.y - lastMousePosition.y;

										  //Must ensure the numbers are non negative
										  if (deltaX < 0)
											  deltaX = deltaX * -1;
										  if (deltaY < 0)
											  deltaY = deltaY * -1;

										  //If the mouse has moved horizontally
										  if (deltaX > 2){
											  if (key1)
											  {
												  windmill1Base.rotate(bodyAngleAmount * deltaTIme);
											  }
											  else if (key2)
											  {
												  windmill2Base.rotate(bodyAngleAmount * deltaTIme);
											  }
											  else if (key3)
											  {

												  windmill3Base.rotate(bodyAngleAmount * deltaTIme);
											  }
											  else if (key4OrA)
											  {
												  windmill1Base.rotate(bodyAngleAmount * deltaTIme);
												  windmill2Base.rotate(bodyAngleAmount * deltaTIme);
												  windmill3Base.rotate(bodyAngleAmount * deltaTIme);

											  }
										  }

										  //If the mouse has moved vertically
										  if (deltaY > 2) {
											  if (key1)
												  tranformWind1.rotate(1.0f, { 100.0f, 300.0f });
											  else if (key2)
												  tranformWind2.rotate(1.0f, { windmill1Base.getLocalBounds().width / 2.0f, windmill1Base.getLocalBounds().height / 2.0f });
											  else if (key3)
												  tranformWind3.rotate(1.0f, { windmill2Base.getLocalBounds().width / 2.0f, windmill2Base.getLocalBounds().height / 2.0f });
											  else if (key4OrA) {
												  // rotate around corner of screen
												  tranformWind1.rotate(1.0f, { 100.0f, 300.0f });
												  // rotate around left windmill
												  tranformWind2.rotate(1.0f, { windmill1Base.getLocalBounds().width / 2.0f, windmill1Base.getLocalBounds().height / 2.0f });
												  tranformWind3.rotate(1.0f, { windmill2Base.getLocalBounds().width / 2.0f, windmill2Base.getLocalBounds().height / 2.0f });

											  }
										  }

										  lastMousePosition = mousePosition;
			}
				break;

			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}

		}

		secondTimer += deltaTIme;

		//Setting up the scrolling background
		
		sf::IntRect deltaRect = backgroundRect;
		deltaRect.left = backgroundRect.left + (int)(movementSpeed * secondTimer);
		backSprite.setTextureRect(deltaRect);

		// Check if more than a second has elapsed, as that's all we're checking.
		if (secondTimer > 1.0f)
		{
			/* Remove a second from timer (we can't set it to 0 because there's a chance that a small
			* fraction of a second has elapsed, and we don't want to lose that). eg. 1.001f */
			secondTimer -= 1.0f;
			backgroundRect.left += (int)movementSpeed; // Add on the appropriate offset.

			/* We don't want our offset to get too big, so what we do is check to see if it's larger than our
			* texture. If it is, we can safely subtract the size of our texture from the rectangle's offset and
			* see the exact same point on the texture. (if width = 100, then we don't want the offset to be 1300
			* when 1300 looks exactly like 100 because of the repeating texture; this makes our numbers much easier
			* to work with. */
			if (backgroundRect.left >= (float)background.getSize().x) {
				backgroundRect.left -= background.getSize().x;
			}
		}

		window.clear(); // draw fullscreen graphic

		//Drawing all elements
		window.draw(backSprite);
		windmill1BaseTrans.Draw(&window, tranformWind1);
		windmill2BaseTrans.Draw(&window, tranformWind2);
		windmill3BaseTrans.Draw(&window, tranformWind3);

		window.display();
	}

	return 0;
}