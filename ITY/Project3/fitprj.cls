%% pro ��ely 3. projektu ITY upravil Pavel Smr�
%% m�sto \usepackage[czech]{babel} --> \usepackage{czech}
%% definice projectITY3 pro p��kaz \FITproject{ITY3}
%%
%%%% hacked by PP - POZOR - jen pro �eskou verzi
%%
%% This is file `fitprj.cls',
%% generated with the docstrip utility.
%%
%% The original source files were:
%%
%% fitprj.dtx  (with options: `class')
%%
%% (C) 2002 David Rezac
%%
\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{fitprj}%
    [2002/07/20 Dokumentarni trida pro projekty FIT VUT Brno]
\let\ifczech\iffalse
\DeclareOption{czech}{\let\ifczech\iftrue}
\DeclareOption*{}
\ProcessOptions\relax
\ifx\pdfoutput\undefined % nejedeme pod pdftexem
  \LoadClass[a4paper,oneside,onecolumn,11pt]{report}
\else
  \LoadClass[pdftex,a4paper,oneside,onecolumn,11pt]{report}
\fi
\usepackage{mathptm}

\ifx\pdfoutput\undefined  % nejedeme pod pdftexem
  \ifczech
    \usepackage{czech}
    %\main@language{czech}
    \usepackage[latin2]{inputenc}
  \else
    \usepackage[english]{babel}
  \fi
  \usepackage{graphics}
  \usepackage{epsfig}
\else % je to pdftex !
  \ifczech
    \usepackage{czech}
    %\main@language{czech}
    \usepackage[latin2]{inputenc}
  \else
    \usepackage[english]{babel}
  \fi
  \usepackage[pdftex]{graphicx}
\fi
\setlength{\hoffset}{-0.7cm}
\setlength{\voffset}{-1.5cm}
\setlength{\textheight}{23.0cm}
\setlength{\textwidth}{15.2cm}

\hfuzz2pt % nehl�sit over-full boxy < 2pt
\ifczech
  \def\@vutname{Vysok� u�en� technick� v~Brn�}
  \def\@vutnameL{Vysok�m u�en� technick�m v~Brn�}    % *L -> lokal
  \def\@fitname{Fakulta informa�n�ch technologi�}
  \def\@fitnameA{Fakultu informa�n�ch technologi�}  % *A -> akuzativ
  \def\@fitnameL{Fakult� informa�n�ch technologi�}
  \def\@uifsname{�stav informa�n�ch syst�m�}
  \def\@upsyname{�stav po��ta�ov�ch syst�m�}
  \def\@uitsname{�stav inteligentn�ch syst�m�}
  \def\@upgmname{�stav po��ta�ov� grafiky a multim�di�}
  \def\@uifsnameL{�stavu informa�n�ch syst�m�}
  \def\@upsynameL{�stavu po��ta�ov�ch syst�m�}
  \def\@uitsnameL{�stavu inteligentn�ch syst�m�}
  \def\@upgmnameL{�stavu po��ta�ov� grafiky a multim�di�}

  \def\@keywordsnameCZ{Kl��ov�  slova}
  \def\@keywordsname{Keywords}
  \def\@abstractnameCZ{Abstrakt}
  \def\@abstractname{Abstract}
  \def\@projectBP{Bakal��sk� pr�ce}
  \def\@projectRP{Ro�n�kov� projekt}
  \def\@projectSP{Semestr�ln� projekt}
  \def\@projectDP{Diplomov� pr�ce}
  \def\@projectPGST{Teze}
  \def\@projectPGSD{Diserta�n� pr�ce}
  \def\@projectITY3{Projekt ITY �. 3}

  \def\@grantstuff{{\em Tato pr�ce vznikla jako �koln� d�lo
   na Vysok�m u�en� technick�m v Brn�, Fakult� informa�n�ch technologi�.
   Pr�ce je chr�n�na autorsk�m z�konem
   a jej� u�it� bez ud�len� opr�vn�n� autorem je nez�konn�, s v�jimkou
   z�konem definovan�ch p��pad�. }}
  \def\@authsign{Podpis autora}
  \def\@suprsign{Podpis �kolitele}
  \def\@submittext{Odevzd�no na Fakult� informa�n�ch technologi� %
  Vysok�ho u�en� technick�ho v Brn� %
  }
  \def\@acknowname{Pod�kov�n�}
  \def\@prohlaseni{Prohl�en�}
  \def\@tocheader{Obsah}
\else
  \def\@vutname{Brno University of Technology}
  \def\@vutnameL{\@vutname}
  \def\@fitname{Faculty of Information Technology}
  \def\@fitnameL{\@fitname}
  \def\@uifsname{Department of Information Systems}
  \def\@upsyname{Department of Computer Systems}
  \def\@uitsname{Department of Intelligent Systems}
  \def\@upgmname{Department of Computer Graphics and Multimedia}

  \def\@keywordsname{Keywords}
  \def\@abstractname{Abstract}
  \def\@projectBP{Bachelor project}
  \def\@projectRP{Two-semester project}
  \def\@projectSP{Semester project}
  \def\@projectDP{MSc. Thesis}
  \def\@projectPGST{Thesis}
  \def\@projectPGSD{Doctoral Thesis}

  \def\@grantstuff{{\em The author thereby grants to \@vutname \@fitname
                   persmission to reproduce and distribute copies
   of this thesis document in whole or in part.}}
  \def\@authsign{Signiture of the Author}
  \def\@suprsign{Certified by}
  \def\@submittext{Submitted %to the {\em \@departmentname}
                   in partial %%%% as??? PP
                   fulfillment of the requirements for
   \@requirementstext at}
  \def\@acknowname{Acknowledgements}
  \def\@tocheader{Contents}
\fi
\renewcommand\maketitle{%
  \pagestyle{empty}
  \null
  \begin{center}%
  \vspace{5mm}
    {\LARGE \bf \sc \MakeUppercase{\@vutname} }\\[5mm]%
    {\Large \bf \sc \MakeUppercase{\@fitname} }\\[5mm]%
    %{\Large \bf \sc \MakeUppercase{\@departmentname} }%
    \vspace{10mm}

    \begin{figure}[h]
      \begin{center}
        \includegraphics[width=3cm,keepaspectratio]{vut_fit}
      \end{center}
    \end{figure}

    \vspace{20mm}

    {\Huge \bfseries \@title}\\[5mm]
    {\Large \@projecttype}

    \vfill
    \Large{\bfseries \@year \hfill \@author }

  \end{center}%
  \clearpage

  \setcounter{tocdepth}{2}

\addtocounter{page}{1}

}
\newcommand{\grantrights}{%
  \thispagestyle{empty}

  \begin{center}
    {\Huge \bf \@title}\\[5mm]
  \end{center}
   \vspace{5mm}

   \noindent \@submittext \   %
   %\vspace{5mm}
   %\begin{center}
   %  {\Large \sc \MakeUppercase{\@vutnameL} }\\[5mm]
   %  {\Large \sc \MakeUppercase{\@fitnameL} }\\[5mm]
   %  \@date
   \\  dne \@date
   %\end{center}

   \vspace{10mm}
   \noindent \copyright \quad \@author, \@year \\[10mm]
   \@grantstuff

  \vfill

%%%% PP
  \ifx\undefined\@prohlaseni
  \else
    \noindent{\Large \bf \@prohlaseni}\\[5mm]
    \noindent {\@prohlasenitext}
  \fi
  \vspace{15mm}
%%%

  \begin{flushright}
      \makebox[4cm]{\dotfill} \\
      {\em \@author}\\
      \@date\\[10mm]
  \end{flushright}

  \clearpage
}

\newcommand{\abstractkeywords}{%
  \thispagestyle{empty}
  \noindent {\Large \bf \@abstractname}\\[5mm]
  \@abstracttext

  \vspace{3cm}
  \noindent {\Large \bf \@keywordsname}\\[5mm]
  \@keywordstext

\ifczech
\else
  \ifx\undefined\@acknowledgementstext
  \else
    \vfill

    \noindent{\Large \bf \@acknowname}\\[5mm]

    \noindent {\@acknowledgementstext}
  \fi
\fi

  \clearpage
}

\ifczech
\newcommand{\abstractkeywordsCZ}{%
  \thispagestyle{empty}
  \noindent {\Large \bf \@abstractnameCZ}\\[5mm]
  \@abstracttextCZ

  \vspace{3cm}
  \noindent {\Large \bf \@keywordsnameCZ}\\[5mm]
  \@keywordstextCZ

\ifczech
  \ifx\undefined\@acknowledgementstext
  \else
     \vfill

     \noindent{\Large \bf \@acknowname}\\[5mm]

     \noindent {\@acknowledgementstext}
  \fi
\fi

  \clearpage
}
\fi

\newcommand{\FITstart}{%
  \pagestyle{plain}

  \addcontentsline{toc}{chapter}{\@tocheader}

  \tableofcontents
  \clearpage
}
\def\@projecttype{}
\def\@departmentname{}
\def\@departmentnameL{}
\def\@requirementstext{}
\def\@year{\number\year}

\newcommand{\submit}[1]{%
  \def\@submittext{#1}
}

\newcommand{\edeclaration}[1]{%
  \def\@prohlasenitext{#1}
}
\newcommand{\fitabstract}[1]{%
  \def\@abstracttext{#1}
}
\newcommand{\keywords}[1]{%
  \def\@keywordstext{#1}
}

\ifczech
\newcommand{\fitabstractCZ}[1]{%
  \def\@abstracttextCZ{#1}
}
\newcommand{\keywordsCZ}[1]{%
  \def\@keywordstextCZ{#1}
}
\fi

\newcommand{\requirements}[1]{%
  \def\@requirementstext{#1}
}

\newcommand{\acknowledgements}[1]{%
  \def\@acknowledgementstext{#1}
}

\newcommand{\setyear}[1]{%
  \def\@year{#1}
}

\newif\ifnasel
\naselfalse

\def\ifEqString#1#2#3#4{\def\testa{#1}\def\testb{#2}%
   \ifx\testa\testb
   \def#4{#3}
   \naseltrue
   \fi
}
\newcommand{\FITdepartment}[1]{%
  \ifEqString{#1}{UIFS}{\@uifsname}{\@departmentname}
  \ifEqString{#1}{UPSY}{\@upsyname}{\@departmentname}
  \ifEqString{#1}{UITS}{\@uitsname}{\@departmentname}
  \ifEqString{#1}{UPGM}{\@upgmname}{\@departmentname}
  \ifnasel
    \ifEqString{#1}{UIFS}{\@uifsnameL}{\@departmentnameL}
    \ifEqString{#1}{UPSY}{\@upsynameL}{\@departmentnameL}
    \ifEqString{#1}{UITS}{\@uitsnameL}{\@departmentnameL}
    \ifEqString{#1}{UPGM}{\@upgmnameL}{\@departmentnameL}
  \else
     \def\@departmentname{Nezn�m� �stav!}{\@departmentname}
      \typeout{ fitprj.cls �patn� n�zev �stavu !}
  \fi
  \naselfalse
}
\newcommand{\FITproject}[1]{%
  \ifEqString{#1}{BP}{\@projectBP}{\@projecttype}
  \ifEqString{#1}{RP}{\@projectRP}{\@projecttype}
  \ifEqString{#1}{SP}{\@projectSP}{\@projecttype}
  \ifEqString{#1}{DP}{\@projectDP}{\@projecttype}
  \ifEqString{#1}{PGST}{\@projectPGST}{\@projecttype}
  \ifEqString{#1}{PGSD}{\@projectPGSD}{\@projecttype}
  \ifEqString{#1}{ITY3}{\@projectITY3}{\@projecttype}
  \ifnasel
  \else
     \def\@departmentname{Nezn�m� typ projektu!}{\@projecttype}
      \typeout{ fitprj.cls �patn� typ projektu !}
  \fi
  \naselfalse
}
\def\uv#1{\iflanguage{english}{``#1''}%
                              {\quotedblbase #1\textquotedblleft}}%
\catcode`\"=\active
\def"{\bgroup
    \iflanguage{english}%
        {``\def"{''\egroup}}%
        {\quotedblbase\def"{\textquotedblleft\egroup}}}

\endinput
%%
%% End of file `fitprj.cls'.
