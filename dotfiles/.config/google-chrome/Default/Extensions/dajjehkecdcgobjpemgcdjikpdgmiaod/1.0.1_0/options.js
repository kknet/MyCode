// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

'use strict';

let o_method_src = '';
let o_methods = document.getElementsByName('o_method');
let o_save_btn = document.getElementById('o_save_btn');

chrome.storage.sync.get('open_method', function(data) {
    o_method_src = data.open_method;
    for(let i = 0; i < o_methods.length; i++){
        if (o_methods[i].value == o_method_src){
            o_methods[i].checked = true;
            break;
        }
    }
});

o_save_btn.addEventListener('click', function() {
    let o_method = '';
    for(let i = 0; i < o_methods.length; i++){
        if (o_methods[i].checked){
            o_method = o_methods[i].value;
            break;
        }
    }
    chrome.storage.sync.set({open_method: o_method}, function() {
        console.log('set o_method_src to ' + o_method);
        document.getElementById('hint').innerHTML = '保存成功！';
    })
});