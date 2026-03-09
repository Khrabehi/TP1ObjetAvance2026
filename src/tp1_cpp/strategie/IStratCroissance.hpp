
#pragma once

class ICroissance;

class IStratCroissance
{
	public:
		virtual void setStrategieCroissance(ICroissance* croissance) = 0;
};
