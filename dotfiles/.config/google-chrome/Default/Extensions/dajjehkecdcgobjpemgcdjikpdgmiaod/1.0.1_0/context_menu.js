// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// A generic onclick callback function.
function genericOnClick(info, tab) {    
    var itemId = info.menuItemId;
    var parseUrl = "";
    if (itemId == "context_page"){
        parseUrl = "http://www.flvcd.com/parse.php?kw=" + 
            encodeURIComponent(tab.url);
    }
    else if (itemId == "context_selection"){
        if (info.selectionText.indexOf("http://") == 0 || 
            info.selectionText.indexOf("https://") == 0){
            parseUrl = "http://www.flvcd.com/parse.php?kw=" + 
                encodeURIComponent(info.selectionText);
        }
        else{
            alert('只能选择链接来解析哦！');
            return;
        }
    }
    else if (itemId == "context_link"){
        parseUrl = "http://www.flvcd.com/parse.php?kw=" + 
            encodeURIComponent(info.linkUrl); 
    }
    doParse(tab, parseUrl);
    //console.log("item " + info.menuItemId + " was clicked");
    //console.log("info: " + JSON.stringify(info));
    //console.log("tab: " + JSON.stringify(tab));
}

function doParse(tab, parseUrl){
    chrome.storage.sync.get('open_method', function(data) {
        var get_o_method = data.open_method;
        console.log("get_o_method=" + get_o_method);
        if (get_o_method == "current") chrome.tabs.update(tab.id, {url: parseUrl});
        else chrome.tabs.create({url: parseUrl});
    });
}

var contexts = ["page", "selection", "link"];
for (var i = 0; i < contexts.length; i++) {
    var context = contexts[i];
    var title = "用FLVCD解析本页视频";
    if (context == "selection") title = "用FLVCD解析选中的链接";
    else if (context == "link") title = "用FLVCD解析该链接";
    var id = chrome.contextMenus.create({"title": title, "contexts":[context], 
        "onclick": genericOnClick, "id": "context_" + context});
}

chrome.runtime.onInstalled.addListener(function() {
    chrome.storage.sync.set({open_method: 'current'}, function() {
        console.log('The open_method is current.');
    }
)});

chrome.browserAction.onClicked.addListener(
    function callback(){
        chrome.tabs.query({active: true, currentWindow: true}, function(tabs){
            var activeTab = tabs[0];
            var parseUrl = "http://www.flvcd.com/parse.php?kw=" + 
                encodeURIComponent(activeTab.url);
            doParse(activeTab, parseUrl);             
        });
    }
);