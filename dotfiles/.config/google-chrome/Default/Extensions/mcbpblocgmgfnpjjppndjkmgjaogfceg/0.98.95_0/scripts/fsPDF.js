var fsPDF=function(b,l){function f(b,a,f){var c=1===arguments.length?b:Array.prototype.join.call(arguments," ");u.push(c);n+=c.length+1}function k(b,a,h){h?m.unshift(n):m.push(n);h=h?1:++q;var c;a&&(c="/Length "+a.length);f(h+" 0 obj\r\n<<"+b+(c?c:"")+">>");a&&(f("stream"),f(a),f("endstream"));f("endobj");return h}var r=[],u=[],m=[],t=[],n=0,q=1,y=b.width,p=b.height,v,w,x;return{toDataURL:function(){var q=btoa;f("%PDF-1.6\r\n%\u00ffGenerated by FireShot [http://getfireshot.com]\u00ff");if(l.length){for(var a in l){var h=
l[a],c="http://getfireshot.com/pdf_"+btoa(l[a].a);if(t[c])var e=t[c];else e=k("/Type/Action/S/URI/URI("+c+")"),t[c]=e;h.nActionId=e}for(d in l){a=l[d];for(var g in a.r){h=a.nActionId;e=a.r[g];c=p-Math.max(0,e[1]);var z=Math.min(b.width,e[0]+e[2]),A=p-Math.min(b.height,e[1]+e[3]);e=[(.75*Math.max(0,e[0])).toFixed(2),(.75*A).toFixed(2),(.75*z).toFixed(2),(.75*c).toFixed(2)].join(" ");r.push(k("/Type/Annot/BS<</W 0 /S /S>>/C[0 1 0]/Subtype/Link/Rect["+e+"]/A "+h+" 0 R"))}}}var d="/Type /XObject /Subtype /Image /Width "+
b.width+" /Height "+b.height+" /ColorSpace /DeviceRGB /BitsPerComponent 8 /Filter /DCTDecode ";g=atob(b.toDataURL("image/jpeg").replace("data:image/jpeg;base64,",""));d=k(d,g);d=k("/ProcSet[/PDF/ImageC]/XObject<</I0 "+d+" 0 R>>");g=k("","q\r\n"+(.75*b.width).toFixed(2)+" 0 0 "+(.75*b.height).toFixed(2)+" 0 "+(.75*(p-b.height)).toFixed(2)+" cm\r\n/I0 Do\r\nQ");a="";r.length&&(a="/Annots["+r.join(" 0 R ")+" 0 R]");v=k("/Type/Page/Parent 1 0 R/MediaBox[0 0 "+(.75*y).toFixed(2)+" "+(.75*p).toFixed(2)+
"]/Contents "+g+" 0 R/Resources "+d+" 0 R"+a);w=k("/Type/Catalog/Pages 1 0 R");k("/Type/Pages /Kids ["+v+" 0 R] /Count 1",null,!0);x=n;f("\r\nxref\r\n0 "+(m.length+1)+"\r\n0000000000 65535 f");for(d=0;d<m.length;++d){for(g=m[d].toString();10>g.length;)g="0"+g;f(g+" 00000 n")}f("trailer\r\n<</Root "+w+" 0 R /Size "+(m.length+1)+">>\r\n");f("startxref\r\n"+x+"\r\n%%%%EOF\r\n");d=u.join("\n");return"data:application/pdf;base64,"+q(d)}}};
