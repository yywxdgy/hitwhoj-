function execClipboardEvent(selector, name) {
  return page.evaluate((selector, name) => {
    const el = document.querySelector(selector);
    const e = new CustomEvent(name);
    window.puppeteerClipboard = window.puppeteerClipboard || new Map();
    e.clipboardData = {
      files: [],
      getData(k) {
        return puppeteerClipboard.get(k);
      },
      setData(k, v) {
        puppeteerClipboard.set(k, v);
      },
    };
    el.dispatchEvent(e);
  }, selector, name);
}

const clipboard = {
  copy: (selector) => execClipboardEvent(selector, 'copy'),
  cut: (selector) => execClipboardEvent(selector, 'cut'),
  paste: (selector) => execClipboardEvent(selector, 'paste'),
  clear: () => page.evaluate(() => (window.puppeteerClipboard = undefined)),
};