#include "Platform.h"

void Platform::Draw(Camera& camera) const
{
	PutImageAlpha(camera, render_position.x, render_position.y, img);

	if (is_debug)
	{
		setlinecolor(RGB(255, 0, 0));
		DebugLine(camera, shape.left, shape.y, shape.right, shape.y);
	}
}