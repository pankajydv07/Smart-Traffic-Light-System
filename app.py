from flask import Flask, jsonify
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)

@app.route('/traffic_light', methods=['GET'])
def traffic_light():
    # Call the updated C++ executable
    result = subprocess.run(['./SmartTrafficLight'], capture_output=True, text=True)
    light_color = result.stdout.strip()
    return jsonify({"color": light_color})

if __name__ == '__main__':
    app.run(debug=True, port=5001)
