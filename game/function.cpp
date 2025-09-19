#include "function.h"


bool function::isPointInPolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon) {
    int windingNumber = 0;

    for (size_t i = 0; i < polygon.size(); ++i) {
        sf::Vector2f start = polygon[i];
        sf::Vector2f end = polygon[(i + 1) % polygon.size()]; // Wrap around to the first point

        if (start.y <= point.y) {
            if (end.y > point.y) {
                float crossProduct = (end.x - start.x) * (point.y - start.y) -
                    (point.x - start.x) * (end.y - start.y);
                if (crossProduct > 0) {
                    ++windingNumber;
                }
            }
        }
        else {
            if (end.y <= point.y) {
                float crossProduct = (end.x - start.x) * (point.y - start.y) -
                    (point.x - start.x) * (end.y - start.y);
                if (crossProduct < 0) {
                    --windingNumber;
                }
            }
        }
    }

    return windingNumber != 0; // Non-zero winding number means the point is inside
}

bool function::isMovementAllowed(const sf::Vector2f& newplayerpostion, const std::vector<std::vector<sf::Vector2f>>& terrains)
{
    for (const auto& terrain : terrains) {
        if (isPointInPolygon(newplayerpostion, terrain)) {
            return false;
        }
    }
    return true;
}

void function::handleterraincollsion(sf::Vector2f& mapOffset,const sf::Vector2f& playerposition, std::vector<std::vector<sf::Vector2f>>& terrains)
{

	sf::Vector2f newplayerposition = playerposition + mapOffset;
	for (const auto& terrain : terrains) {
		for (size_t i = 0; i < terrain.size() - 1; ++i)
		{
			sf::Vector2f start = terrain[i];
			sf::Vector2f end = terrain[i + 1];
			if (newplayerposition.x >= start.x && newplayerposition.x <= end.x) {

				float slope = (end.y - start.y) / (end.x - start.x);
				float terrainY = start.y + slope * (newplayerposition.x - start.x);
				
				if (newplayerposition.y > terrainY) {
					mapOffset.y -= (newplayerposition.y - terrainY);
				}

				
			}
		}
	}
}
