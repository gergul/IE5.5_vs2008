
#include "stdafx.h"
#include "testdoc.h"

#include <exdisp.h>

#include <wmp.h>

// {6BF52A4F-394A-11d3-B153-00C04F79FAA6}
static const GUID IID_IWMPPlayer = 
{ 0x6BF52A4F, 0x394A, 0x11d3, { 0xB1, 0x53, 0x00, 0xC0, 0x4F, 0x79, 0xFA, 0xA6 } };

CDocument* pDoc = NULL;

XINDOWS_PUBLIC void TestDoc(HWND hWndParent)
{
    CEnsureThreadState ets;

    InitDocClass();

    pDoc = new CDocument();
    pDoc->Init();
    pDoc->InitNew();
    pDoc->RunningToInPlace(hWndParent, NULL);

    CElement* pBody = NULL;
    pDoc->_pPrimaryMarkup->CreateElement(ETAG_BODY, &pBody);
    pDoc->_pPrimaryMarkup->Root()->InsertAdjacent(CElement::AfterBegin, pBody);

    {
        CElement* pDiv = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_DIV, &pDiv);
        IHTMLStyle* pIDivStyle = NULL;
        pDiv->get_style(&pIDivStyle);
        CVariant vt(VT_BSTR);
        vt.bstrVal = L"360px";
        pIDivStyle->put_height(vt);
        vt.bstrVal = L"192px";
        pIDivStyle->put_width(vt);
        vt.vt = VT_EMPTY;
        pIDivStyle->put_background(L"green");
        pIDivStyle->put_cursor(L"hand");
        pIDivStyle->Release();
        pBody->InsertAdjacent(CElement::BeforeEnd, pDiv);

        CElement* pP = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_P, &pP);
        pDiv->InsertAdjacent(CElement::BeforeEnd, pP);
        IHTMLStyle* pIPStyle = NULL;
        pP->get_style(&pIPStyle);
        pIPStyle->Release();
        IHTMLElement* pIP = NULL;
        pP->QueryInterface(IID_IHTMLElement, (void**)&pIP);
        pIP->put_innerText(L"如果你想尝试一下不用表格来排版网页，而是用CSS来排版你的网页，也就是常听的用DIV来编排你的网页结构，又或者说你想学习网页标准设计，再或者说你的上司要你改变传统的表格排版方式，提高企业竞争力，那么你一定要接触到的一个知识点就是CSS的盒子模型，div排版的核心所在，传统的表格排版是通过大小不一的表格和表格嵌套来定位排版网页内容，而改用CSS排版后，就是通过由CSS定义的大小不一的盒子和盒子嵌套来编排网页。");
        pIP->Release();
        pP->Release();

        pDiv->Release();
    }

    {
        CElement* pDiv = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_DIV, &pDiv);
        IHTMLStyle* pIDivStyle = NULL;
        pDiv->get_style(&pIDivStyle);
        pIDivStyle->Release();
        pBody->InsertAdjacent(CElement::BeforeEnd, pDiv);

        CElement* pP = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_P, &pP);
        pDiv->InsertAdjacent(CElement::BeforeEnd, pP);
        IHTMLStyle* pIPStyle = NULL;
        pP->get_style(&pIPStyle);
        pIPStyle->Release();
        IHTMLElement* pIP = NULL;
        pP->QueryInterface(IID_IHTMLElement, (void**)&pIP);
        pIP->put_innerText(L"对于一个好的 UI，一个很重要的方面就是要能及时的与用户发生交互。对于按钮来说，我们需要让按钮相应各种鼠标事件，让用户知道它是可以按下的。如上图，我们要制作的按钮共有三种状态：正常状态、鼠标划过、鼠标按下。通常情况下，我们会想到利用 onclick、onmouseover 这样的事件来控制。");
        pIP->Release();
        pP->Release();

        pDiv->Release();
    }

    // image
    {
        CElement* pImage = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_IMAGE, &pImage);
        pBody->InsertAdjacent(CElement::BeforeEnd, pImage);

        IHTMLImgElement* pIImg = NULL;
        pImage->QueryInterface(IID_IHTMLImgElement, (void**)&pIImg);
        pIImg->put_src(L"http://www.wzdq123.com/static/images/logo.gif");
        pIImg->Release();

        pImage->Release();
    }

    // DW toolbar
    {
        CElement* pDiv = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_DIV, &pDiv);
        pBody->InsertAdjacent(CElement::BeforeEnd, pDiv);

        {
            IHTMLElement* pIDivElement = NULL;
            pDiv->QueryInterface(IID_IHTMLElement, (void**)&pIDivElement);
            pIDivElement->put_id(L"info");
            pIDivElement->Release();
        }

        pDiv->Release();
    }

    {
        CElement* pInput = NULL;
        pDoc->_pPrimaryMarkup->CreateElement(ETAG_TEXTAREA, &pInput);
        pBody->InsertAdjacent(CElement::BeforeEnd, pInput);

        IHTMLStyle* pIInputStyle = NULL;
        pInput->get_style(&pIInputStyle);
        CVariant vt(VT_BSTR);
        vt.bstrVal = L"360px";
        pIInputStyle->put_height(vt);
        vt.bstrVal = L"192px";
        pIInputStyle->put_width(vt);
        vt.vt = VT_EMPTY;
        pIInputStyle->put_background(L"green");
        pIInputStyle->Release();

        pInput->Release();
    }

    pBody->Release();
}

XINDOWS_PUBLIC void TestMoveDoc(RECT& rc)
{
    if(pDoc)
    {
        pDoc->SetObjectRects(&rc, &rc);
    }
}

XINDOWS_PUBLIC void TestDelDoc()
{
    if(pDoc)
    {
        pDoc->InPlaceToRunning();
        pDoc->Release();
    }
}

XINDOWS_PUBLIC HRESULT TestTranslateAccelerator(LPMSG lpMsg)
{
    HRESULT hr = S_FALSE;
    if(pDoc)
    {
        hr = pDoc->TranslateAccelerator(lpMsg);
    }
    return hr;
}