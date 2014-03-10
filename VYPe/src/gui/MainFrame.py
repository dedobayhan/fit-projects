# -*- coding: utf-8 -*-
# generated by wxGlade 0.6.3 on Wed Oct  7 22:13:19 2009
#
# Project: VYPe - Conversion from regular expressions to finite automata
# Authors:
#     Libor Polčák, xpolca03@stud.fit.vutbr.cz
#     Petr Zemek, xzemek02@stud.fit.vutbr.cz
# Date: 4.10.2009
#

import wx
import os

from messages import *
from nfa2img import createNFAImages, CreateNFAImageError
from ..dot2img import DotProgramError
from ..regexp_parser import RegExpParser
from ..tree2nfa import tree2nfa

# begin wxGlade: dependencies
# end wxGlade

# begin wxGlade: extracode

# end wxGlade

class MainFrame(wx.Frame):
    def __init__(self, *args, **kwds):
        # begin wxGlade: MainFrame.__init__
        kwds["style"] = wx.DEFAULT_FRAME_STYLE
        wx.Frame.__init__(self, *args, **kwds)
        self.panelSizerControls = wx.Panel(self, -1)
        self.lblInsertRegExp = wx.StaticText(self.panelSizerControls, -1, "Input regular expression:")
        self.inputRegExp = wx.TextCtrl(self.panelSizerControls, -1, "", style=wx.TE_PROCESS_ENTER)
        self.btnProcessRegExp = wx.Button(self.panelSizerControls, -1, "Process", style=wx.BU_EXACTFIT)
        self.btnFirst = wx.Button(self.panelSizerControls, -1, "|<", style=wx.BU_EXACTFIT)
        self.btnPrevious = wx.Button(self.panelSizerControls, -1, "<", style=wx.BU_EXACTFIT)
        self.btnNext = wx.Button(self.panelSizerControls, -1, ">", style=wx.BU_EXACTFIT)
        self.btnLast = wx.Button(self.panelSizerControls, -1, ">|", style=wx.BU_EXACTFIT)
        self.panelShownRegExpTop = wx.Panel(self.panelSizerControls, -1)
        self.lblShownRegExp = wx.StaticText(self.panelSizerControls, -1, "")
        self.panelShownRegExpBottom = wx.Panel(self.panelSizerControls, -1)
        self.lblFontSize = wx.StaticText(self.panelSizerControls, -1, "Font size:")
        self.spinFontSize = wx.SpinCtrl(self.panelSizerControls, -1, "", min=10, max=32)
        self.lblHighlightColour = wx.StaticText(self.panelSizerControls, -1, "Highlight colour:")
        self.comboHighlightColour = wx.ComboBox(self.panelSizerControls, -1, choices=["Black", "Blue", "Brown", "Cyan", "Green", "Magenta", "Navy", "Orange", "Red"], style=wx.CB_DROPDOWN|wx.CB_DROPDOWN|wx.CB_READONLY|wx.CB_SORT)
        self.panelNFABitmap = wx.Panel(self, -1, style=wx.TAB_TRAVERSAL|wx.FULL_REPAINT_ON_RESIZE)

        self.__set_properties()
        self.__do_layout()

        self.Bind(wx.EVT_TEXT_ENTER, self.inputRegExpTextEnter, self.inputRegExp)
        self.Bind(wx.EVT_TEXT, self.inputRegExpTextChanged, self.inputRegExp)
        self.Bind(wx.EVT_BUTTON, self.btnProcessRegExpClicked, self.btnProcessRegExp)
        self.Bind(wx.EVT_BUTTON, self.btnFirstClicked, self.btnFirst)
        self.Bind(wx.EVT_BUTTON, self.btnPreviousClicked, self.btnPrevious)
        self.Bind(wx.EVT_BUTTON, self.btnNextClicked, self.btnNext)
        self.Bind(wx.EVT_BUTTON, self.btnLastClicked, self.btnLast)
        self.Bind(wx.EVT_SPINCTRL, self.onSpinFontSizeCtrl, self.spinFontSize)
        self.Bind(wx.EVT_COMBOBOX, self.onComboHiglightColourCombobox, self.comboHighlightColour)
        # end wxGlade
        # Initialize instance variables
        wx.EVT_PAINT(self.panelNFABitmap, self.onPaint)
        wx.EVT_SIZE(self.panelNFABitmap, self.onPanelNFABitmapResize)
        wx.EVT_CHAR(self.lblInsertRegExp, self.onKeyUp)
        wx.EVT_KEY_UP(self.btnProcessRegExp, self.onKeyUp)
        wx.EVT_KEY_UP(self.btnFirst, self.onKeyUp)
        wx.EVT_KEY_UP(self.btnPrevious, self.onKeyUp)
        wx.EVT_KEY_UP(self.btnNext, self.onKeyUp)
        wx.EVT_KEY_UP(self.btnLast, self.onKeyUp)
        wx.EVT_KEY_UP(self.panelShownRegExpTop, self.onKeyUp)
        wx.EVT_KEY_UP(self.lblShownRegExp, self.onKeyUp)
        wx.EVT_KEY_UP(self.panelShownRegExpBottom, self.onKeyUp)
        wx.EVT_KEY_UP(self.lblFontSize, self.onKeyUp)
        wx.EVT_KEY_UP(self.panelNFABitmap, self.onKeyUp)
        self.spinFontSize.SetValue(self.spinFontSize.GetFont().GetPointSize())
        self.__regexp = None
        self.__step = 0
        self.__productList = []
        self.__nfaImgs = []
        self.__bitmap = None

    def __set_properties(self):
        # begin wxGlade: MainFrame.__set_properties
        self.SetTitle("VYPe 2009: Demonstration of conversion from regular expression to NFA")
        self.SetSize((800, 400))
        self.SetFocus()
        self.inputRegExp.SetToolTipString("Input regular expression\n\\e is epsilon\n\\0 is empty set\nAll unicode characters including spaces except the ones mentioned in this help represent themselves\nWhen r, s are valid regular expressions\nrs is concatenation of r and s\nr+s is union of r and s\nr* is iteration of r\nUse brackets () to change priorities\n\n\\+ is symbol +\n\\* is symbol *\n\\\\ is symbol \\\n\\( is symbol (\n\\( is symbol (")
        self.inputRegExp.SetFocus()
        self.btnProcessRegExp.Enable(False)
        self.btnFirst.Enable(False)
        self.btnPrevious.Enable(False)
        self.btnNext.Enable(False)
        self.btnLast.Enable(False)
        self.comboHighlightColour.SetSelection(8)
        # end wxGlade

    def __do_layout(self):
        # begin wxGlade: MainFrame.__do_layout
        sizerTop = wx.BoxSizer(wx.VERTICAL)
        sizerMain = wx.BoxSizer(wx.VERTICAL)
        sizerControls = wx.BoxSizer(wx.HORIZONTAL)
        sizerFontSize = wx.BoxSizer(wx.VERTICAL)
        sizerShownRegExp = wx.BoxSizer(wx.VERTICAL)
        sizerUserInput = wx.BoxSizer(wx.VERTICAL)
        sizerCommandButtons = wx.BoxSizer(wx.HORIZONTAL)
        sizerUserInput.Add(self.lblInsertRegExp, 10, wx.ALL|wx.EXPAND|wx.FIXED_MINSIZE, 2)
        sizerUserInput.Add(self.inputRegExp, 10, wx.ALL|wx.EXPAND|wx.FIXED_MINSIZE, 2)
        sizerCommandButtons.Add(self.btnProcessRegExp, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 0)
        sizerCommandButtons.Add(self.btnFirst, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 0)
        sizerCommandButtons.Add(self.btnPrevious, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 0)
        sizerCommandButtons.Add(self.btnNext, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 0)
        sizerCommandButtons.Add(self.btnLast, 1, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL, 0)
        sizerUserInput.Add(sizerCommandButtons, 10, wx.EXPAND, 0)
        sizerControls.Add(sizerUserInput, 4, wx.EXPAND, 0)
        sizerShownRegExp.Add(self.panelShownRegExpTop, 1, wx.EXPAND|wx.ALIGN_RIGHT, 0)
        sizerShownRegExp.Add(self.lblShownRegExp, 0, wx.ALL, 2)
        sizerShownRegExp.Add(self.panelShownRegExpBottom, 1, wx.EXPAND|wx.ALIGN_RIGHT, 0)
        sizerControls.Add(sizerShownRegExp, 4, wx.EXPAND, 0)
        sizerFontSize.Add(self.lblFontSize, 0, wx.ALL, 2)
        sizerFontSize.Add(self.spinFontSize, 0, wx.ALL|wx.EXPAND|wx.ALIGN_RIGHT, 2)
        sizerFontSize.Add(self.lblHighlightColour, 0, 0, 0)
        sizerFontSize.Add(self.comboHighlightColour, 0, wx.EXPAND|wx.ALIGN_RIGHT, 0)
        sizerControls.Add(sizerFontSize, 0, wx.ALIGN_RIGHT, 0)
        self.panelSizerControls.SetSizer(sizerControls)
        sizerMain.Add(self.panelSizerControls, 1, wx.EXPAND, 0)
        sizerTop.Add(sizerMain, 0, wx.EXPAND, 0)
        sizerTop.Add(self.panelNFABitmap, 1, wx.EXPAND|wx.FIXED_MINSIZE, 0)
        self.SetSizer(sizerTop)
        self.Layout()
        # end wxGlade
        self.SetMinSize((800, 400))

    def inputRegExpTextEnter(self, event): # wxGlade: MainFrame.<event_handler>
        self.__processRegExp(self.__getCurrentRegExp())
        self.btnProcessRegExp.SetFocus()
        self.__setProperFocus()
        event.Skip()

    def inputRegExpTextChanged(self, event): # wxGlade: MainFrame.<event_handler>
        if self.inputRegExp.GetValue() == "":
            self.btnProcessRegExp.Enable(False)
        else:
            self.btnProcessRegExp.Enable(True)
        event.Skip()

    def btnProcessRegExpClicked(self, event): # wxGlade: MainFrame.<event_handler>
        self.__processRegExp(self.__getCurrentRegExp())
        self.__setProperFocus()
        event.Skip()

    def btnFirstClicked(self, event): # wxGlade: MainFrame.<event_handler>
        if self.btnFirst.Enabled:
            self.__step = 0
            self.__showStep()
        self.__setProperFocus()
        event.Skip()

    def btnPreviousClicked(self, event): # wxGlade: MainFrame.<event_handler>
        if self.btnPrevious.Enabled:
            self.__step = self.__step - 1
            self.__showStep()
        self.__setProperFocus()
        event.Skip()

    def btnNextClicked(self, event): # wxGlade: MainFrame.<event_handler>
        if self.btnNext.Enabled:
            self.__step = self.__step + 1
            self.__showStep()
        self.__setProperFocus()
        event.Skip()

    def btnLastClicked(self, event): # wxGlade: MainFrame.<event_handler>
        if self.btnLast.Enabled:
            self.__step = len(self.__productList) - 1
            self.__showStep()
        self.__setProperFocus()
        event.Skip()

    def onPaint(self, event):
        dc = wx.PaintDC(self.panelNFABitmap)

        # Set background to white
        dc.SetBackground(wx.Brush(wx.Colour(255, 255, 255)))

        dc.Clear()
        if self.__bitmap != None:
            dc.DrawBitmap(self.__bitmap[1], 3, 3)

    def onKeyUp(self, event):
        """ Main application on key up handler. """
        keyCode = event.GetKeyCode()
        focus = self.FindFocus()
        if focus not in [self.inputRegExp, self.spinFontSize]:
            if keyCode in [wx.WXK_LEFT, wx.WXK_DOWN]:
                self.btnPreviousClicked(type("", (object,), {"Skip": lambda self: None})())
            elif keyCode in [wx.WXK_RIGHT, wx.WXK_UP]:
                self.btnNextClicked(type("", (object,), {"Skip": lambda self: None})())
            elif keyCode in [wx.WXK_HOME, wx.WXK_PAGEDOWN, wx.WXK_NUMPAD_HOME, wx.WXK_NUMPAD_PAGEDOWN]:
                self.btnFirstClicked(type("", (object,), {"Skip": lambda self: None})())
            elif keyCode in [wx.WXK_END, wx.WXK_PAGEUP, wx.WXK_NUMPAD_END, wx.WXK_NUMPAD_PAGEUP]:
                self.btnLastClicked(type("", (object,), {"Skip": lambda self: None})())
        event.Skip()

    def onPanelNFABitmapResize(self, event):
        self.__fitNFABitmapToPanel()

    def onSpinFontSizeCtrl(self, event): # wxGlade: MainFrame.<event_handler>
        """Event handler"""
        if self.__regexp != None:
            step = self.__step
            self.__processRegExp(self.__regexp)
            self.__step = step
            self.__showStep()
        fontSize = self.spinFontSize.GetValue()
        newFont = self.lblShownRegExp.GetFont()
        newFont.SetPointSize(fontSize)
        self.lblShownRegExp.SetFont(newFont)
        self.inputRegExp.SetFont(newFont)
        proportion = int(((fontSize-10)/15.0+1)*10)
        sizerItem = self.panelSizerControls.GetSizer().GetItem(self.inputRegExp, True)
        if os.name == 'nt':
            # MS Windows HACK: There are some resizing problems on this system,
            # so temporarily increase the proportion, do layout and then set
            # the proper one (see two lines below)
            sizerItem.SetProportion(proportion+4)
            self.Layout()
        sizerItem.SetProportion(proportion)
        self.Layout()
        self.__setProperFocus()
        event.Skip()

    def onComboHiglightColourCombobox(self, event): # wxGlade: MainFrame.<event_handler>
        """Event handler"""
        if self.__regexp != None:
            step = self.__step
            self.__processRegExp(self.__regexp)
            self.__step = step
            self.__showStep()
        self.__setProperFocus()
        event.Skip()

    def __setProperFocus(self):
        """Sets focus to an element which will not cause any problems when
        moving forwards and backwards using arrows and other keyboard shortcuts.

        This function should be called after button clicks and after elements
        loose their focus (like pressing enter after a regular expression is
        typed).
        """
        # This is just a pure HACK to get rid of keyboard shortcuts problems
        # in MS Windows XP (movement keys caused unwanted focus changes).
        # When focus is set to the bitmap panel, it won't leave it
        # after some keyboard shortcut is used.
        self.panelNFABitmap.SetFocus()

    def __getCurrentRegExp(self):
        """Returns the current regexp from the input field."""
        regexp = self.inputRegExp.GetValue()
        # On Debian, regexp has type 'str', but on Ubuntu it has type 'unicode',
        # so convert it to unicode to avoid encoding problems
        if (type(regexp) != type(unicode())):
            regexp = unicode(regexp, 'utf8')
        return regexp

    def __processRegExp(self, regexp):
        """Process the given regexp and initalize the GUI so the user can
        explore the transition.
        """
        try:
            self.__regexp = regexp
            regexpTree = RegExpParser.parseRegExp(regexp)
            self.__productList = tree2nfa(regexpTree)
            self.__nfaImgs = createNFAImages(map(lambda (a, _): a,
                    self.__productList), self.spinFontSize.GetValue()*1.4,
                    self.comboHighlightColour.GetValue())
            self.__step = 0
            self.__showStep()
        except ValueError, e:
            displayErrorMessage(self, e.message)
        except RuntimeError, e:
            if e.message.startswith(u"maximum recursion depth exceeded"):
                displayErrorMessage(self, "Inserted regular expression is too long to be parsed.")
            else:
                displayErrorMessage(self, "Runtime error: " + e.message)

    def __showNFAImage(self, nfaImg):
        """Shows the given image of an NFA.

        nfaImg - wx representation of an image (wx.Image instance)
        """
        assert isinstance(nfaImg, wx.Image), nfaImg.__class__
        self.__bitmap = (nfaImg, wx.BitmapFromImage(nfaImg))
        self.__fitNFABitmapToPanel()

    def __fitNFABitmapToPanel(self):
        """Checks if the currently shown automaton is able to fit in the panel.

        If the check is not succesfull, image will be rescaled so it
        will fit to the panel.
        """
        if self.__bitmap != None:
            nfaImg = self.__bitmap[0]
            # Get panel and image width
            panelWidth, panelHeight = self.panelNFABitmap.GetClientSize()
            imageWidth, imageHeight = nfaImg.GetSize()
            if imageHeight > panelHeight or imageWidth > panelWidth:
                # Find out the minimal ratio which should be used
                heightRatio = float(panelHeight) / imageHeight
                widthRatio = float(panelWidth) / imageWidth
                ratio = min(heightRatio, widthRatio)
                # Rescale bitmap
                nfaCopy = nfaImg.Copy()
                rescaledBitmap = wx.BitmapFromImage(nfaCopy.Rescale(
                  imageWidth*ratio, imageHeight*ratio))
                self.__bitmap = (nfaImg, rescaledBitmap)
            else:
                self.__bitmap = (nfaImg, wx.BitmapFromImage(nfaImg))

    def __showStep(self):
        """Enables and disables button and changes automaton for selected step"""
        focused = self.FindFocus()
        self.btnFirst.Enable(False)
        self.btnPrevious.Enable(False)
        self.btnNext.Enable(False)
        self.btnLast.Enable(False)
        self.lblShownRegExp.SetLabel("")

        productsReady = len(self.__productList)
        if productsReady > 0:
            self.lblShownRegExp.SetLabel(unicode(self.__step+1) + "/" +
                unicode(productsReady) + ": " + unicode(self.__productList[self.__step][1]))
            try:
                self.__showNFAImage(self.__nfaImgs[self.__step])
            except CreateNFAImageError, e:
                errMsgStart = "The 'dot' program call (part of the graphviz package) " +\
                    "returned with an error. "
                # Try to provide more meaningful error message
                # (magical constant is used because I'm afraid to put a symbolic constant
                # for it anywhere into this generated file)
                if len(self.__regexp) > 100:
                    # The 'dot' program segfaults when converting too big NFA
                    displayErrorMessage(self, errMsgStart + "The NFA for the current " +\
                        "regular expression is probably too big, so the 'dot' program " + \
                        "cannot handle it correctly. Please try a shorter regular expression.")
                else:
                    displayErrorMessage(self, errMsgStart + "Please make sure you have " +\
                        "the graphviz package installed, the 'dot' program is in the $PATH " +\
                        "and your temporary directory is writeable.")

        if self.__step > 0:
            self.btnFirst.Enable(True)
            self.btnPrevious.Enable(True)
        if self.__step < (productsReady - 1):
            self.btnNext.Enable(True)
            self.btnLast.Enable(True)

        if focused != None:
            focused.SetFocus()
            focused = self.FindFocus()
            if focused != None and not focused.Enabled:
              self.panelNFABitmap.SetFocus()
        self.Refresh()

# end of class MainFrame
