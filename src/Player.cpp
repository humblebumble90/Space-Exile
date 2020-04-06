#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "BulletManager.h"
#include "ScoreBoard.h"

Player::Player(std::string imagePath, std::string name,
	GameObjectType type, glm::vec2 position)
	: m_name(name), m_alpha(255), m_maxSpeed(7.5f), m_fireRate(3.0f), m_coolTime(0.0f)
,hp(5),m_invCoolTime(0.0f)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

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
		auto bullet = BulletManager::Instance()->getBullet();
		bullet->setPosition
		(glm::vec2(getPosition().x + 10.0f, getPosition().y));
		bullet->activate(true);
		m_coolTime = m_fireRate;
	}
}

void Player::hit()
{
	hp -= 1;
	Scoreboard::Instance()->setHP(hp);
	beInvincible();
}

int Player::getPlayerHP()
{
	return hp;
}

bool Player::getInvincible()
{
	return inv;
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
	m_alpha = 122;
	inv = true;
	m_invCoolTime = 30.0f;
}
