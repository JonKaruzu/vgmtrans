#pragma once
#include "Format.h"
#include "Root.h"
#include "TriAcePS1Scanner.h"

using namespace std;

BEGIN_FORMAT(TriAcePS1)
	USING_SCANNER(TriAcePS1Scanner)
END_FORMAT()
