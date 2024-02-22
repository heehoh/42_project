#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import cgi

# 파일 업로드 메소드(CGI에서 호출)
def handle_file_upload():
    form = cgi.FieldStorage()
    
    if 'file' in form:
        file_item = form['file']
        
        if file_item.filename:
            upload_dir = os.environ.get('WEBSERV_ROOT', '') + os.environ.get('UPLOAD_DIR', '/')
            os.makedirs(upload_dir, exist_ok=True)
            file_path = os.path.join(upload_dir, file_item.filename)

            if os.path.exists(file_path):
                return 400, "Bad Request", "<h2>파일 업로드 실패</h2><p>동일한 이름의 파일이 이미 존재합니다.</p>"
            with open(file_path, 'wb') as file:
                file.write(file_item.file.read())

            # 파일 업로드 성공 메시지 출력
            upload_success_html = f"<h2>파일 업로드 성공</h2><p>파일이 성공적으로 업로드되었습니다. 저장된 파일: <a href='/file/{file_item.filename}'>{file_item.filename}</a></p>"
            # 업로드 후 파일 목록 출력
            return 201, "Created", upload_success_html
        else:
            return 400, "Bad Request", "<h2>파일 업로드 실패</h2><p>올바른 파일을 선택하세요.</p>"
    else:
        return 400, "Bad Request", "<h2>파일 업로드 실패</h2><p>파일이 선택되지 않았습니다.</p>"

# 파일 삭제 메소드(CGI에서 호출)
def delete_file():
    file_info = os.environ.get('PATH_INFO', '')
    if file_info == '':
        return 204, "No Content", "<h2>파일 삭제 실패</h2><p>존재하지 않는 파일입니다.</p>"
    upload_dir = os.environ.get('UPLOAD_DIR', '/')
    webserv_root = os.environ.get('WEBSERV_ROOT', '')
    file_path = webserv_root + upload_dir + file_info
    if os.path.exists(file_path):
        try:
            os.remove(file_path)
            return 202, "Accepted", "<h2>파일 삭제 성공</h2><p>파일을 삭제하는데 성공했습니다.</p>"
        except:
            return 204, "No Content", "<h2>파일 삭제 실패</h2><p>파일을 삭제하는데 실패하였습니다.</p>"
    else:
        return 204, "No Content", "<h2>파일 삭제 실패</h2><p>존재하지 않는 파일입니다.</p>"



# 파일 목록 출력(CGI에서 호출)
def print_file_list():
    upload_dir = os.environ.get('WEBSERV_ROOT', '') + os.environ.get('UPLOAD_DIR', '/')
    file_list_html = "<ul>"
    for filename in os.listdir(upload_dir):
        file_list_html += f'<div><a href="/file/{filename}">{filename}</a>'
        file_list_html += f'''
            <form id="deleteForm" method="DELETE" action="python/upload.py/{filename}">
                <input type="hidden" name="_method" value="DELETE">
                <input type="submit" value="삭제">
            </form>
        </div>
        '''
    file_list_html += "</ul>"
    return file_list_html

# HTML 페이지 출력
def print_html_head():
		print('''
					<!DOCTYPE html>
					<html lang="ko">
							<head>
								<meta charset="UTF-8"/>
								<title>파일 저장소</title>
        <style>
        body {
            font-family: 'Arial', sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            text-align: center;
        }

        h1 {
            color: #333;
            padding: 20px;
            background-color: #fff;
            margin: 0;
        }

        form {
            margin: 20px;
            padding: 20px;
            background-color: #fff;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        label {
            font-size: 18px;
            color: #333;
        }

        input[type="file"] {
            margin-top: 10px;
            padding: 10px;
            font-size: 16px;
            border: 1px solid #ccc;
            border-radius: 5px;
        }

        input[type="submit"] {
            margin-top: 10px;
            padding: 10px 20px;
            font-size: 18px;
            background-color: #4caf50;
            color: #fff;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }

        ul {
            list-style: none;
            padding: 0;
            margin: 20px;
            display: flex;
            justify-content: space-around;
            flex-wrap: wrap;
        }

        div {
            background-color: #fff;
            padding: 10px;
            margin: 10px;
            border-radius: 5px;
            box-shadow: 0 0 5px rgba(0, 0, 0, 0.1);
        }

        a {
            font-size: 16px;
            color: #333;
            text-decoration: none;
        }

        form[id^="deleteForm"] {
            display: inline-block;
            margin-left: 10px;
        }

        form[id^="deleteForm"] input[type="submit"] {
            background-color: #e74c3c;
            color: #fff;
        }
    </style>
							</head>
							<body>
								<h1>파일 저장소</h1>
				''')

# POST 요청 처리(CGI에서 실행)
if os.environ['REQUEST_METHOD'] == 'POST':
    status, message, body = handle_file_upload()
    print(f'Status: {status} {message}', end='\r\n')
    print('Content-type: text/html', end='\r\n\r\n')
    print_html_head()
    print(body)
    print('</body></html>')

# DELETE 요청 처리(CGI에서 실행)
if os.environ['REQUEST_METHOD'] == 'DELETE':
    status, message, body = delete_file()
    print(f'Status: {status} {message}', end='\r\n')
    print('Content-type: text/html', end='\r\n\r\n')
    print_html_head()
    print(body)
    print('</body></html>')


# GET 요청 처리(CGI에서 실행)
if os.environ['REQUEST_METHOD'] == 'GET':
    print(f'Status: 200 OK', end='\r\n')
    print('Content-type: text/html', end='\r\n\r\n')
    print_html_head()
    print('''
		<form method="post" enctype="multipart/form-data" >
    <label for="file">업로드할 파일을 선택하세요</label>
    <br>
    <input type="file" name="file" id="file" accept=".txt, .pdf, .docx, .gif, .jpeg">
    <input type="submit" value="업로드" onclick="uploadFile()">
		</form>
		''')
    print(print_file_list())
    
    # 파일 업로드 기능을 위한 자바스크립트(클라이언트에서 POST 요청을 보내기 위함)
    upload_js = '''
				function uploadFile() {
            event.preventDefault();
						var file = document.getElementById('file').files[0];
						if (!file) {
								alert("파일을 선택하세요 😅");
                return;
            }
            var formData = new FormData();
            formData.append('file', file);
						var xhr = new XMLHttpRequest();
						xhr.open('POST', '/python/upload.py', true);
						xhr.onload = function() {
								if (xhr.status === 201) {
										alert("파일이 성공적으로 업로드되었습니다 🎉");
										location.reload();
								} else {
										alert("파일 업로드에 실패했습니다 😱");
										location.reload();
								}
						};
						xhr.send(formData);
				}
    '''

    # 파일 삭제 기능을 위한 자바스크립트(클라이언트에서 DELETE 요청을 보내기 위함)
    delete_js = '''
		document.addEventListener('DOMContentLoaded', function() {
    		var deleteForms = document.querySelectorAll('#deleteForm');
    		deleteForms.forEach(function(form) {
        		form.addEventListener('submit', function(event) {
            		event.preventDefault();
            		var xhr = new XMLHttpRequest();
            		xhr.open('DELETE', form.action, true);
            		xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
            		xhr.onload = function() {
                		if (xhr.status === 202) {
                    		alert("파일이 성공적으로 삭제되었습니다 😃");
                    		location.reload();
                		} else {
												alert("파일 삭제에 실패했습니다 😢 ");
												location.reload();
										}
            		};
            		xhr.send('_method=DELETE');
        		});
    		});
		});
		'''
    
    print(f'<script>{upload_js}{delete_js}</script>')			
    print('</body></html>')

