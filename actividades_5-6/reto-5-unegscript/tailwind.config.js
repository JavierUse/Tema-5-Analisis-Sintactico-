export default {
  content: ["./index.html", "./src/**/*.{js,ts,jsx,tsx}"],
  theme: {
    extend: {
      colors: {
        background: "#FFF1E6",
        card: "#E2ECE9",
        primary: "#CDDAFD",
        secondary: "#FDE2E4",
        border: "#DBE7E4",
        foreground: "#2C3A35",
        muted: "#5A706A",
      },
      boxShadow: {
        soft: "0 20px 40px rgba(44, 58, 53, 0.08)",
      },
    },
  },
  plugins: [],
};
