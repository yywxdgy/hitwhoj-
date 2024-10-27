const axios = require('axios');
const fs = require('fs');
const path = require('path');
const args = process.argv.slice(2);

async function run(id) {
    // console.log("Loading the page...", ' ');
    
    const url = `http://localhost:8080/problem/${id}/submit?_data=routes%2Fproblem%2F%24problemId%2Fsubmit`;
    let cookies=JSON.parse(fs.readFileSync('cookies.json', 'utf8'));
    cookies=cookies.map(cookie=>cookie.name+'='+cookie.value).join('; ');
    let codes=String(fs.readFileSync("main.cpp", 'utf8'));
    const config = {
        method : 'post',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            'Cookie': cookies,
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64)'
        },
        data: {
            "_data": "routes/problem/$problemId/submit",
            "language": "cpp",
            "code": codes
        }
    };
    await axios(url, config).then((res) => {
        console.log(res.data);
    }).catch((err) => {
        console.log(err);
    });
}

run(args[0]);