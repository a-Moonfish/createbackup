void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.color10", normfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", selfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", selbgcolor);
				XRDB_LOAD_COLOR("dwm.color3", selbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color9", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color12", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color11", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", hidfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", urgfloatcolor);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}
