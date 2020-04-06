#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "BulletManager.h"
#include "ScoreBoard.h"

Player::Player(std::string imagePath, std::string name,
	GameObjectType type, glm::vec2 position)
	: m_name(name), m_alpha(255), m_ShieldAlpha(255), m_maxSpeed(7.5f), m_fireRate(3.0f), m_coolTime(0.0f)
	, hp(5), m_invCoolTime(0.0f), m_protected(false), shieldCoolTime(0.0f), powerUpLev(0)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/shield_aurora.png", "shield_aurora"
	,TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);

	std::cout << "Player instantiated!\n";
}

Player::~Player()
{
}

void Player::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
	if(m_protected)
	{
		TheTextureManager::Instance()->draw("shield_aurora", xComponent, yComponent,
			TheGame::Instance()->getRenderer(), 0, m_ShieldAlpha, true);
	}
}

void Player::update()
{

	checkBound();
	movebyState();


	if (m_coolTime > 0)
	{
		m_coolTime -= 0.1f;
	}
	if(m_invCoolTime > 0)
	{
		m_invCoolTime -= 0.1f;
	}
	if(m_invCoolTime <= 0)
	{
		inv = false;
		m_alpha = 255;
	}
	if(shieldCoolTime > 0)
	{
		shieldCoolTime -= 0.1f;
		m_ShieldAlpha--;
	}
	if(shieldCoolTime <= 0)
	{
		m_protected = false;
		m_ShieldAlpha = 255;
	}
}

void Player::clean()
{
}

void Player::move(Move newMove)
{
	switch (newMove)
	{
	case RIGHT:
		setVelocity(glm::vec2(1.0f * m_maxSpeed, getVelocity().y));
		break;
	case LEFT:
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, getVelocity().y));
		break;
	case UP:
		setVelocity(glm::vec2(getVelocity().x, -1.0f * m_maxSpeed));
		break;
	case DOWN:
		setVelocity(glm::vec2(getVelocity().x, 1.0f * m_maxSpeed));
		break;
	}

}

void Player::fire()
{
	if(m_coolTime <= 0)
	{
		m_pLaser = BulletManager::Instance()->getBullet();
		m_pLaser->setPosition
		(glm::vec2(getPosition().x + 10.0f, getPosition().y));
		m_pLaser->activate(true);
		if(powerUpLev >= 1)
		{
			m_pLaser = BulletManager::Instance()->getBullet();
			m_pLaser->setPosition
			(glm::vec2(getPosition().x + 10.0f, getPosition().y));
			m_pLaser->setVelocity(
				glm::vec2(
					m_pLaser->getVelocity().x, -45.0f * m_pLaser->getVelocity().x * glm::pi<float>() / 180));
			m_pLaser->activate(true);
		}
		if(powerUpLev == 2)
		{
			m_pLaser = BulletManager::Instance()->getBullet();
			m_pLaser->setPosition
			(glm::vec2(getPosition().x + 10.0f, getPosition().y));
			m_pLaser->setVelocity(
				glm::vec2(m_pLaser->getVelocity().x, 45.0f * m_pLaser->getVelocity().x * glm::pi<float>() / 180));
			m_pLaser->activate(true);
		}
		SoundManager::Instance()->playSound("fire", 0);
		m_coolTime = m_fireRate;
	}
}

void Player::hit()
{
	if(!m_protected)
	{
		hp -= 1;
		ScoreBoard::Instance()->setHP(hp);
		SoundManager::Instance()->playSound("hit", 0);
		beInvincible();
	}
}

int Player::getPlayerPowLev()
{
	return powerUpLev;
}

void Player::setPlayerPowLev(int num)
{
	powerUpLev += num;
}

int Player::getPlayerHP()
{
	return hp;
}

bool Player::getInvincible()
{
	return inv;
}

void Player::protect(bool newState)
{
	m_protected = newState;
	if(m_protected)
	{
		m_ShieldAlpha = 255;
		shieldCoolTime = 25.5f;
	}
}

bool Player::isProtected()
{
	return m_protected;
}

void Player::checkBound()
{
	if (getPosition().x <= Config::SCREEN_WIDTH * 0.03f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.03f, getPosition().y));
	}
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.97f)
	{
		setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.97f, getPosition().y));
	}
	if (getPosition().y <= Config::SCREEN_HEIGHT * 0.03f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.03f));
	}
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.97f)
	{
		setPosition(glm::vec2(getPosition().x, Config::SCREEN_HEIGHT * 0.97f));
	}
}

void Player::movebyState()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
}

void Player::beInvincible()
{
	std::cout << "Invincible \n";
	m_alpha *= 0.5;
	inv = true;
	m_invCoolTime = 15.0f;
}
