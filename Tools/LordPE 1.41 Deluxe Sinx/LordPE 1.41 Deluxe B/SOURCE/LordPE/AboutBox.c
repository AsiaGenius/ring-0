//
// AboutBox.c
// ----------
//
// This is a little excerpt from the LordPE source code, in fact the about dialog box.
// Many people asked me how this link lable technique works, so here we go...
//
// yoda (29th November 2002)
//

LRESULT __stdcall AboutStaticsProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_MOUSEMOVE:
		if (hActiveLnk != hWnd)
		{
			InvalidateRect(hWnd, NULL, TRUE);
			hActiveLnk = hWnd;
		}
		break;
	}
	return CallWindowProc(pStaticWndProc, hWnd, Msg, wParam, lParam);
}

BOOL __stdcall AboutDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HFONT         hfSel, hfNoSel;
	LOGFONT              lf;
	static HCURSOR       hcLink;
	static HWND          hMailAddr, hHome;
	HDC                  hDC;

	switch(uMsg)
	{
	case WM_INITDIALOG:
		hMailAddr = GetDlgItem(hDlg, A_MAILADDR);
		hHome = GetDlgItem(hDlg, A_WWWHOME);
		hcLink = LoadCursor(hInst, (LPSTR)IDC_LINK);
		SetClassLong(hMailAddr, GCL_HCURSOR, (DWORD)hcLink);

		// get font handles for underlined and not underlined statics
		memset(&lf, 0, sizeof(lf));
		lf.lfHeight = 14;
		lf.lfWidth  = 9;
		lstrcpy(lf.lfFaceName, "TERMINAL");
		lf.lfWeight = 200;
		lf.lfCharSet = OEM_CHARSET;
		lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
		lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfPitchAndFamily = FF_SCRIPT;
		hfNoSel = CreateFontIndirect(&lf);
		lf.lfUnderline = TRUE;
		hfSel = CreateFontIndirect(&lf);

		// hook static wnd procs
		pStaticWndProc = (WNDPROC)SetWindowLong(
			hMailAddr,
			GWL_WNDPROC,
			(DWORD)AboutStaticsProc);
		SetWindowLong(
			hHome,
			GWL_WNDPROC,
			(DWORD)AboutStaticsProc);
		return TRUE;

	case WM_CTLCOLORSTATIC:
		hDC = (HDC)wParam;
		if (hMailAddr == (HWND)lParam || // a link static ?
			hHome == (HWND)lParam)
		{
			SetBkMode(hDC, TRANSPARENT);
			if (hActiveLnk == (HWND)lParam)
			{
				SetTextColor(hDC, 0x000000FF);
				SelectObject(hDC, hfSel);
			}
			else
			{
				SelectObject(hDC, hfNoSel);
				SetTextColor(hDC, 0x00FF0000);
			}
			return (BOOL)GetSysColorBrush(0);
		}
		return FALSE;

	case WM_MOUSEMOVE:
		if (hActiveLnk)
		{
			InvalidateRect(hMailAddr, NULL, FALSE);
			InvalidateRect(hHome, NULL, FALSE);
		}
		hActiveLnk = 0;
		return TRUE;

	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		// handle static clicks
		case A_MAILADDR:
			ShellExecute(hDlg, "open", "MailTo:LordPE@gmx.net", NULL, NULL, SW_MAXIMIZE);
			SendMessage(hDlg, WM_MOUSEMOVE, 0, 0);
			return TRUE;

		case A_WWWHOME:
			ShellExecute(hDlg, "open", "http://y0da.cjb.net/", NULL, NULL, SW_MAXIMIZE);
			SendMessage(hDlg, WM_MOUSEMOVE, 0, 0);
			return TRUE;
		}
		break;

	case WM_CLOSE:
		// clean up
		DeleteObject(hfSel);
		DeleteObject(hfNoSel);
		DestroyCursor(hcLink);
		// close dlg
		EndDialog(hDlg, 0);
		return TRUE;
	}

	return FALSE;
}
