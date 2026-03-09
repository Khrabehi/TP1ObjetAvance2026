
#pragma once

#include "IFabrique.hpp"

#include <memory>
#include <optional>
#include <string>

class FabriqueBase : public IFabrique
{
	public:
		std::optional<std::unique_ptr<Vegetal>> creerVegetal(const std::string& donnees) override;
};
