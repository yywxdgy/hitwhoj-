const puppeteer = require('puppeteer');
const fs = require('fs');
const path = require('path');
const args = process.argv.slice(2);

async function run(id) {
    // console.log("Loading the page...", ' ');
    
    const url = `http://1.94.128.12/problem/${id}/submit`;
    const browser = await puppeteer.launch({ headless: "new" });
    const page = await browser.newPage();
    await page.goto(url, { waitUntil: 'networkidle2' });

    // console.log("Done.");
    // console.log("Reading the file(main.cpp)...");
    

    let codes;
    let file = path.resolve(__dirname, './main.cpp');
    fs.readFile(file, 'utf8', (err, data) => {
        if (err) throw err;
        codes = String(data).replaceAll("    ", "");
    });

    // console.log("Done.");
    // console.log("Reading the file(cookies.json)...");

    let cookies=JSON.parse(fs.readFileSync('cookies.json', 'utf8'));
    
    // console.log("Done.");
    // console.log("Setting the cookies...");
    
    
    await page.setCookie(...cookies);
    await page.reload();

    // console.log("Done.");
    // console.log("Submitting the code...");

    const text = codes;
    const block = 'body > div > div.drawer-content.flex.h-full.flex-col > div.flex-1.p-6 > div > form > div:nth-child(2) > textarea';
    const submit = 'body > div > div.drawer-content.flex.h-full.flex-col > div.flex-1.p-6 > div > form > div:nth-child(3) > button';
    const language = 'body > div > div.drawer-content.flex.h-full.flex-col > div.flex-1.p-6 > div > form > div:nth-child(1) > select';

    await page.waitForSelector(block);
    await page.waitForSelector(language);
    await page.select(language, 'cpp');
    await page.click(block);
    const lines = text.split('\n');
    for (const line of lines) {
        const te = String(line);
        await page.keyboard.type(te);
        await page.keyboard.press('Delete');
        await page.keyboard.press('Delete');
    }
    await page.waitForSelector(submit);
    await page.click(submit);

    // console.log("Submitted.");
    
    await browser.close();
}

run(args[0]);